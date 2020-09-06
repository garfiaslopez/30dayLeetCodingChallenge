// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/is-subsequence/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p1 = 0;
        
        for (int i=0; i<t.length(); i++) {
            if (p1<s.length() && s[p1] == t[i]) {
                p1++;
            }
        }
        if (p1 == s.length()) {
            return true;
        }
        return false;
    }
};