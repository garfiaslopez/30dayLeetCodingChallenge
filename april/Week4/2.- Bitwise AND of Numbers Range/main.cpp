// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m >= INT_MAX-1) return m&n;
        int sum = m;
        for(int i=m+1; i<=n; i++) {
            sum &= i;
            if (sum == 0) return 0;
        }
        return sum;
    }
};