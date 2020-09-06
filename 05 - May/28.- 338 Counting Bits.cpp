// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/counting-bits
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    vector<int> applyingMaskCountingInChunks(int num) {
        vector<int> result;
        int bitsInNum[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };
        int mask = 15; // 4bits
        
        for (int i=0; i<=num; i++) {
            
            int sumOfOnes = 0;
            int currentNum = i;
            
            while(currentNum > 0) {
                int part = currentNum & mask;
                sumOfOnes += bitsInNum[part];
                currentNum = currentNum>>4;
            }
            
            result.push_back(sumOfOnes);
        }
        
        return result;
    }
    
    //Brian Kernighan’s Algorithm:
    vector<int> countBitsWithBrian(int num) {
        vector<int> result;
        for (int i=0; i<=num; i++) {
            
            int sumOfOnes = 0;
            int currentNum = i;
            
            while(currentNum > 0) {
                currentNum = (currentNum & (currentNum -1));
                sumOfOnes++;
            }
            
            result.push_back(sumOfOnes);
        }
        
        return result;
    }
    
    vector<int> countBits(int num) {
        return countBitsWithBrian(num);
    }
};