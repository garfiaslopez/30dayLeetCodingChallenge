// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/length-of-last-word/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int spaces = 0;
        
        for (char c: s) {
            if (c != ' ') {
                if (spaces > 0) {
                    spaces = 0;
                    count = 0;
                }
                count++;
            } else {
                spaces++;
            }
        }
        
        return count;
    }
};