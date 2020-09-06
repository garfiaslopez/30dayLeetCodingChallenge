// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/find-the-duplicate-number/
//
// © Jose Garfias Lopez
//


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        if (nums.size() <= 1) return -1;
        int slow = nums[0];
        int fast = nums[nums[0]];
        int entry = nums[0];
        
        // finding loop with this while as always there will be a loop, here we dont need to check to null values or something like that.
        while(fast != slow) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        // they touched at fast
        fast = nums[fast];
        while(fast != entry) {
            entry = nums[entry];
            fast = nums[fast];
        }
        
        return fast;
    }
};