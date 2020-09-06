// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/excel-sheet-column-number/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    
    int letterToNumber(char c) {
        return c - 'A' + 1;
    }
    
    int titleToNumber(string s) {
        int n = s.length();
        int sum = 0;
        int totalN = 26;
        
        for (int i=0; i<n; i++) {
            int inv = n - i - 1;
            if (i == n - 1) {
                sum += letterToNumber(s[i]);
            } else if (i < s.length() - 1) {
                sum += pow(totalN, inv) *  letterToNumber(s[i]);
            }
            
        }
        
        return sum;
    }
};