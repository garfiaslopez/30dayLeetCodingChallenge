// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 */

class BinaryMatrix {
public:
    int get(int x, int y);
    vector<int> dimensions();
};

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimensions = binaryMatrix.dimensions();
        int maxRowIndex = dimensions[0] - 1;
        int maxColIndex = dimensions[1] - 1;
        int result = -1;
        
        int pointerX = maxRowIndex;
        int pointerY = maxColIndex;
        
        while(pointerX >= 0 && pointerY >= 0) {
            int n = binaryMatrix.get(pointerX, pointerY);
            if (n == 1) {
                result = pointerY;
                pointerY--;
            } else {
                pointerX--;
            }
        }
        
        return result;
    }
};