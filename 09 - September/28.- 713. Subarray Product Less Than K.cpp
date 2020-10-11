// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/subarray-product-less-than-k/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int totalProduct = 1;
        int count = 0;
        
        for (right = 0; right < nums.size(); right++) {
            
            totalProduct *= nums[right];
            
            if (totalProduct >= k) {
                // move left pointer and remove left values from total.
                while (left < nums.size() && totalProduct >= k) {
                    totalProduct /= nums[left];
                    left++;
                }
                
                if (totalProduct < k) {
                    count += right - left + 1;
                }
            } else {
                count += right - left + 1;
            }
            
        }
        
        return count;
    }
};