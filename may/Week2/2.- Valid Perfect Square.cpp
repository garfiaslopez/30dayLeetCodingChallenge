// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        
        // BruteForce Linear Solution
        /*
        for (long int i=1; i<=num; i++) {
            if (i*i == num) return true;
        }
        return false;
        */
        
        // BinarySaerch Log(n) Solution
        if (num == 1) return true;
        
        int left = 1;
        int right = num;
        
        while (left <= right) {
            long int middle = left + (right - left) / 2;
            long int square = middle * middle;
            if (square == num) {
                return true;
            } else if (square < num) {
                left = middle + 1;
            } else {
                right = middle -1;
            }
        }
        return false;
    }
};