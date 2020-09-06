// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/unique-binary-search-trees/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    
    /*
    Using Catalan number calculated with DP. O(n) Space, O(n^2) time
    C = Catalan Number
    C(n) = (C0 * Cn-1) + (C1 * Cn-2) + ... + (Cn-1 * C0);
    C(3) = C0 * C2 + C1 * C1 + C2 * C1;
    
    C(2) = C0 * C1 + C1* C0
    
    If we decompose the trees as we use the ith number as root, we can say that to the left we hace nth elements from the left from te array of the ith element and to the right we hace nth rigth elements ftom the ith position:   1234
    1   R-0, L-3
    2   R-1, L-2
    3   R-2, L-1
    4   R-3, L-0
    */
    
    
    int catalan (int n) {
        vector<int> dp(n+1,0);
        
        dp[0] = dp[1] = 1;
        
        for (int i=2; i<=n; i++) { // iterate until nth catalan
            for (int j=0; j<i; j++) {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        
        return dp[n];
    }
    
    int numTrees(int n) {
        return catalan(n);    
    }
};