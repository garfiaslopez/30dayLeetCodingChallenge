// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/product-of-array-except-self/
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> toLeft;
        vector<int> toRight;
        vector<int> result;
        
        toLeft.resize(nums.size());
        toRight.resize(nums.size());
        result.resize(nums.size());
        
        toLeft[nums.size()-1] = 1;
        toRight[0] = 1;
        
        for (int i=nums.size()-1; i>0; i--) {
            toLeft[i-1] = nums[i] * toLeft[i];
        }
        for (int i=0; i<nums.size()-1; i++) {
            toRight[i+1] = nums[i] * toRight[i];
        }
        for (int i=0; i<nums.size(); i++) {
            result[i] = toLeft[i] * toRight[i];
        }
        
        return result;
    }
};