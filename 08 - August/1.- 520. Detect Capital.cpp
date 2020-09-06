// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/detect-capital/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    bool detectCapitalUse(string word) {
        int uppers=0;
        bool firstUpper=false;
        
        for (int i=0; i<word.length(); i++){
          char c = word[i];
           if (isupper(c)){
             if (i==0) {
               firstUpper=true;
             }
             uppers++;
           } 
        }
        
        if (uppers == word.length()) return true;
        if (firstUpper && uppers==1) return true;
        if (uppers==0) return true;
        return false;
    }
};