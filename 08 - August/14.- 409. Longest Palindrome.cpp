// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/longest-palindrome/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freqMap;
        
        for (char c : s) {
            if (freqMap.find(c) != freqMap.end()) {
                freqMap[c] += 1;
            } else {
                freqMap[c] = 1;
            }
        }
        
        
        int singles = 0;
        int pairs = 0;
        int diffs = 0;
        
        for (auto it : freqMap) {
            diffs++;
            char c = it.first;
            int times = it.second;
            
            if (times == 1) {
                singles += 1;
            } else if (times >=2) {
                pairs += (times / 2);
                singles += times % 2;
            }
        }
        
        int res = pairs * 2;
        if (singles >= 1) {
            res++;
        }
        
        return res;
    }
};