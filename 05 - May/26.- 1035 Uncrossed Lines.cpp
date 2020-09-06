// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/uncrossed-lines
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int sizeA = A.size();
        int sizeB = B.size();
        vector<vector<int>> dp(sizeA+1, vector<int>(sizeB+1, 0));
        
        for (int i=1; i<=sizeA; i++) {
            for (int j=1; j<=sizeB; j++) {
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j]  = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[sizeA][sizeB];
    }
};