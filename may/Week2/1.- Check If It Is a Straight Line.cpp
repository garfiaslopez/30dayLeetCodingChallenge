// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    double getM (vector<int> &first, vector<int> &second) {
        double x1 = first[0];
        double y1 = first[1];
        double x2 = second[0];
        double y2 = second[1];
        return (y2-y1) / (x2-x1);
    }
    
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() <= 1) return false;
        
        double initialM = getM(coordinates[0], coordinates[1]);
        for (int i=2; i<coordinates.size(); i++) {
            double m = getM(coordinates[0], coordinates[i]);
            if (m != initialM) return false;
        }
        return true;
    }
};