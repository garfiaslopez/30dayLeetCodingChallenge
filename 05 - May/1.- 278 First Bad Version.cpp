// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/first-bad-version
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int lower = 1;
        int upper = n;
        int lastBadVersion = -1;
        
        while(lower <= upper) {
            
            int mid = lower + (upper - lower) / 2;
            
            if(isBadVersion(mid)) {
                lastBadVersion = mid;
                upper = mid - 1;
            } else {
                lower = mid + 1;
            }
        }
        
        return lastBadVersion;
    }
};