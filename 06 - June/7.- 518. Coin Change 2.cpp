// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/coin-change-2/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        
        // initialize DP
        for (int i=0; i<=amount; i++) {
            dp[0][i] = 0;
        }
        for (int j=0; j<=n; j++) {
            dp[j][0] = 1;
        }
        
        // RUN DP
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=amount; j++) {
                int k = coins[i-1]; 
                
                if (j<k) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-k];
                }        
                
            }
        }
        
        return dp[n][amount];
    }
};