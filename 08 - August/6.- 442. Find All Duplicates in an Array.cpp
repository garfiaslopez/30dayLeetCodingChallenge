// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/find-all-duplicates-in-an-array/
//
// © Jose Garfias Lopez
//


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> response;

        for (int i=0; i<nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) {
                response.push_back(idx+1);
            } else {
                nums[idx] *= -1;
            }
        }
        
        return response;
    }
};