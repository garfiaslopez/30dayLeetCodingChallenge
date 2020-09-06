// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/jewels-and-stones
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, bool> jewelsMap;
        
        for (char jewel : J) {
            jewelsMap[jewel]=true;
        }
        
        int sum = 0;
        for (char stone: S) {
            if (jewelsMap[stone]) sum++;
        }
        
        return sum;
    }
};