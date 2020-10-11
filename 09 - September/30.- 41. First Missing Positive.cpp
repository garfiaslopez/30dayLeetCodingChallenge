// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/first-missing-positive/
//
// © Jose Garfias Lopez
//


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) return 1;
        set<int> setNums;
        
        for (int n : nums) {
            if (n > 0) {
                setNums.insert(n);
            }
        }
        vector<int> positiveNums;
        for (auto it:setNums) {
            positiveNums.push_back(it);
        }
        
        if (positiveNums.size() == 0) return 1;
        if (positiveNums.size() > 0 && positiveNums[0] > 1) return 1;
        
        bool foundDiff = false;
        for (int i=0; i<positiveNums.size() - 1; i++) {
            if (positiveNums[i+1] - positiveNums[i] > 1) {
                return positiveNums[i] + 1;
            }
        }
    
        if (foundDiff == false) return positiveNums[positiveNums.size()-1] + 1;
        
        return 1;
    }
};
