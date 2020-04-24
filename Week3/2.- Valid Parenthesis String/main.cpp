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
    bool checkValidString(string s) {
        int tam = s.length();
        if (tam < 1) return true;
        
        int balance = 0;
        
        for (int i=0; i<tam; i++) {
            if (s[i] == ')') {
                balance--;
            } else {
                balance++;
            }
            if (balance < 0) return false;
        }
        if (balance == 0) return true;
        
        balance = 0;
        for (int i=tam-1; i>=0; i--) {
            if (s[i] == '(') {
                balance--;
            } else {
                balance++;
            }
            if (balance < 0) return false;
        }
        
        return true;
    }
};