// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/find-the-difference/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        int n = t.length();
        
        for (int i=0; i<n; i++) {
            
            if (i<n-1) {
                if (s[i] != t[i]) {
                    return t[i];
                }
            } else {
                return t[i];
            }
        }
        
        return 'X';
    }
};