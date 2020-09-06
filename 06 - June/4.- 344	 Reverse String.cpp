// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/reverse-string/
//
// © Jose Garfias Lopez
//


class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i=0; i<s.size()/2; i++) {
            int left = i;
            int right = s.size() - 1 - i;
            
            int leftTmp = s[left];
            int rightTmp = s[right];
            
            s[left] = rightTmp;
            s[right] = leftTmp;
        }
    }
};