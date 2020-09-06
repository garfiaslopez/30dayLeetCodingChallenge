// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/repeated-substring-pattern/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    
    /* BRUTE FORCE
    bool isPatternOfS(string pattern, string s) {
        int patternIndex = 0;
        for (int i=0; i<s.length(); i++) {
            patternIndex = i % pattern.length();
            if (s[i] != pattern[patternIndex]) {
                return false;
            }
        }
        if (patternIndex == pattern.length() - 1) {
            return true;
        }
        return false;
    }
    
    bool repeatedSubstringPattern(string s) {
        
        if (s.length() <= 1) return false;
        
        string pattern = "";
        char delimiter;
        for (int i=0; i<s.length()/2; i++) {
            pattern += s[i];
            if (isPatternOfS(pattern, s)) {
                return true;
            }
        }
        return false;
    }
    
    
        NOT INTUITIVE SOLUTION :
        DOUBLE THE STRING AND REMOVE FIRST CHAR AND LAST CHAR AND FIND THE ORIGINAL STR.
        (STR[1-N] + STR[0-N-1]).find(STR) 
    
    
    bool repeatedSubstringPattern(string s) {
        return ((((s.substr(1, s.length())) + (s.substr(0, s.length()-1)) ).find(s)) != -1);
    }
    
    
    */
    /*
        KMP
        First, we build the KMP table.

Roughly speaking, dp[i+1] stores the maximum number of characters that the string is repeating itself up to position i.
Therefore, if a string repeats a length 5 substring 4 times, then the last entry would be of value 15.
To check if the string is repeating itself, we just need the last entry to be non-zero and str.size() to divide (str.size()-last entry).
    */
    bool repeatedSubstringPattern(string str) {
        int i = 1, j = 0, n = str.size();
        vector<int> dp(n+1,0);
        while( i < str.size() ){
            if( str[i] == str[j] ) dp[++i]=++j;
            else if( j == 0 ) i++;
            else j = dp[j];
        }
        return dp[n]&&dp[n]%(n-dp[n])==0;
    }
};