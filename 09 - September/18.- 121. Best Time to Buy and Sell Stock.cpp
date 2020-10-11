// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
//
// © Jose Garfias Lopez
//



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* TLE
        if (prices.size() == 0 || prices.size() == 1) return 0;

        int maxProfit = INT_MIN;
        for(int i=0; i<prices.size(); i++) {
            for(int j=i+1; j<prices.size(); j++) {
                int diff = prices[j] - prices[i];
                if (diff > maxProfit) {
                    maxProfit = diff;
                }
            }
        }
        
        if (maxProfit < 0) {
            return 0;   
        }
        return maxProfit;
        */
        
        /*
                DP 
        */
        if (prices.size() == 0) return 0;
        
        vector<int> dp(prices.size());
        dp[0] = prices[0];
        
        int answer = INT_MIN;
        
        for (int i=1; i<prices.size(); i++) {
            dp[i] = min(dp[i-1], prices[i]);
        }
        
        for (int i=0; i<prices.size(); i++) {
            answer = max(answer, prices[i] - dp[i]);
        }
        
        return answer;
    }
};