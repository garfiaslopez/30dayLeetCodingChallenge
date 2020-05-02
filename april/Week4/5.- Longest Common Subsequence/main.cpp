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
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int> > dp = vector<vector<int> >(m+1, vector<int>(n+1,0));
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                char c1 = text1[i];
                char c2 = text2[j];
                if (c1 == c2) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[m][n];
    }
};