// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/flood-fill
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool inBounds(vector<vector<int>>& image, int row, int col) {
        int maxRow = image.size();
        if (!(row >= 0 && row<maxRow)) return false;
        int maxCol = image[row].size();
        if (!(col >= 0 && col <maxCol)) return false;
        return true;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int,int> > toVisit;
        int rowDir[4] = {-1, 0, 1, 0 };
        int colDir[4] = {0, 1, 0, -1 };
        
        int colorToChange = image[sr][sc];
        if (colorToChange == newColor) return image;
        
        //initialize Q
        toVisit.push(make_pair(sr,sc));
        image[sr][sc] = newColor;

        while(!toVisit.empty()) {
            pair<int,int> visit = toVisit.front();
            toVisit.pop();
            image[visit.first][visit.second] = newColor;

            // search on neighbours
            for (int m=0; m<4; m++) {
                int row = visit.first + rowDir[m];
                int col = visit.second + colDir[m];
                
                if (inBounds(image, row,col) && image[row][col] == colorToChange) {
                    toVisit.push(make_pair(row,col));
                    image[row][col] = newColor;
                }
                
            }
        }
        return image;
    }
};