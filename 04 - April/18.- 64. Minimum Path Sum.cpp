// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/minimum-path-sum/
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int maxFil = grid.size();
        int maxCol = grid[0].size();
        
        vector<vector<int>> dp(maxFil, vector<int>(maxCol,0));
        
        for (int i=0; i<maxFil; i++) {
            for (int j=0; j<maxCol; j++) {
                dp[i][j] += grid[i][j];
                
                if (i>0 && j>0) {
                    dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
                } else if(i>0) {
                    dp[i][j] += dp[i-1][j];
                } else if(j>0) {
                    dp[i][j] += dp[i][j-1];
                }            
            }
        }
        
        return dp[maxFil-1][maxCol-1];
    }
};