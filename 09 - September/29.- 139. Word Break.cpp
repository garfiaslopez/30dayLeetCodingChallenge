// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/word-break/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    
    bool isWordPresentIn(string s, unordered_set<string> &wordSet, unordered_map <string, bool> &dp) {
        if (s.length() == 0) return true;
        
        if (dp.find(s) != dp.end()) return dp[s];
        
        for (int i=1; i<=s.length(); i++) {
            string prefix = s.substr(0,i);
            bool isPrefixInDict = wordSet.find(prefix) != wordSet.end();
            string sufix = s.substr(i,(s.length() - i));
            bool isSomeSufixValid = isWordPresentIn(sufix, wordSet, dp);
            
            if (isPrefixInDict && isSomeSufixValid) {
                dp[s] = true;
                return true;
            }
            
        }
        dp[s] = false;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordMap;        
        for (string word : wordDict) {
            wordMap.insert(word);
        }
        
        unordered_map<string, bool> dp;
        return isWordPresentIn(s, wordMap, dp);
    }
};