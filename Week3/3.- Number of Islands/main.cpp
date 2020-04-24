// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        queue< pair<int,int> > islandStack;
        
        vector<int> fil = { -1, 0, 1, 0  };
        vector<int> col = {  0, 1, 0, -1 };
        
        for (int i=0; i<grid.size();i++) {
            for (int j=0; j<grid[i].size(); j++) {
                
                if (grid[i][j] == '1') {
                    islands++;
                    islandStack.push(make_pair(i,j));
                    grid[i][j] = '2';
                    
                    while(!islandStack.empty()) {
                        pair<int,int> coords = islandStack.front();
                        islandStack.pop();                        
                        for (int m=0; m<4; m++) {
                            int newFil = coords.first + fil[m];
                            int newCol = coords.second + col[m];
                            
                            if (newFil>=0 && newFil<grid.size() && 
                                newCol>=0 && newCol<grid[newFil].size() && 
                                grid[newFil][newCol] == '1') {
                                islandStack.push(make_pair(newFil, newCol));
                                grid[newFil][newCol] = '2';
                            }
                        }
                    }
                }
                
                
            }
        }
        
        return islands;
    }
};