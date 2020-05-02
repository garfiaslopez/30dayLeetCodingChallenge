// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastSafeIndex = nums.size()-1;
        
        for (int i=nums.size()-1; i>=0; i--) {
            if (i + nums[i] >= lastSafeIndex) {
                lastSafeIndex = i;
            }
        }
        
        return lastSafeIndex == 0;
    }
};