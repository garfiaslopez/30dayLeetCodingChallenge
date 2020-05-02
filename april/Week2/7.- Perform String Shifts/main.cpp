// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
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
    string stringShift(string s, vector<vector<int>>& shift) {
        string newString = "";
        newString.resize(s.length());

        int finalShift = 0;

        for (vector<int> movement : shift) {
            if (movement[0] == 0) {
                finalShift -= movement[1];
            } else {
                finalShift += movement[1];
            }
        }
        
        int sizeOfStr = s.length();
        for (int i=0; i<sizeOfStr; i++) {
            int newIndex = ((i + finalShift) % (sizeOfStr));
            if (newIndex < 0) {
                newIndex = sizeOfStr + newIndex;
            }
            newString[newIndex] = s[i];
        }

        return newString;
    }
};