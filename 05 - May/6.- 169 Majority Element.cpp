// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/majority-element
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityValue = nums.size()/2;
        unordered_map <int,int> freqMap;
        
        for (int n: nums) {
            freqMap[n]++;
        }
        
        for (auto freqMapIt: freqMap) {
            if (freqMapIt.second > majorityValue) {
                return freqMapIt.first;
            }
        }
        return -1;
    }
};