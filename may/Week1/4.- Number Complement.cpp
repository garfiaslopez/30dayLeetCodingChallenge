// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;
        int pos = 0;
        int newNumber = 0;
        while(num) {
            if ((num & 1) == 0) {
                newNumber += pow(2, pos); 
            }
            pos++;   // increment the current position multiplier for binary
            num>>=1; // shift bits to right
        }
        return newNumber;
    }
};