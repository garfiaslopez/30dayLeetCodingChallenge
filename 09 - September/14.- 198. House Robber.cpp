// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/house-robber/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    
    int solve(vector<int> &nums, vector<int> &dp, int i) {
        int n = nums.size();
        // base case:
        if (i >= n) {// out of bounds
            return dp[i] = 0; // return and save on dp.
        };
        if (i == n-1) { // final element.
            return dp[i] = nums[i]; // return and save on dp.
        }
        // dp check
        if (dp[i] != -1) {
            return dp[i];
        }
        // no dp, calculate val:
        int maxVal = max(nums[i] + solve(nums, dp, i+2), solve(nums, dp, i+1));
        
        return dp[i] = maxVal; // return and save on dp;
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+10, -1);
        return solve(nums, dp, 0);
    }
};