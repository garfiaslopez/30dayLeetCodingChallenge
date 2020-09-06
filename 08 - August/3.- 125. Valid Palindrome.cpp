// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/valid-palindrome/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    bool isPalindrome(string s) {
        string sanitized = "";
        for (char c : s) {
            if (isalnum(c)) {
                sanitized += c;
            }
        }
                
        int n = sanitized.length();
        for (int i=0; i<n/2; i++) {
            char a = tolower(sanitized[i]);
            char b = tolower(sanitized[n-1-i]);

            if (a != b) {
                return false;
            }
        }
        return true;   
    }
};