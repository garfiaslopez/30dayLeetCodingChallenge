// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/contiguous-array/
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0;
        int balanceSum = 0;
        map<int,int> indexSumMap;
        
        indexSumMap[0] = -1;
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 1) {
                balanceSum++;
            } else {
                balanceSum--;
            }
            
            if (indexSumMap.find(balanceSum) != indexSumMap.end()) {
                int start = indexSumMap[balanceSum];
                int lengthRange = i - start;
                
                if (lengthRange > maxLength) {
                    maxLength = lengthRange;
                }
            } else {
                indexSumMap[balanceSum] = i;
            }
        }
        
        return maxLength;
    }
};