// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/word-pattern/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int idChar = 0;
        int idString = 0;
        unordered_map<char,int> seenChar;
        unordered_map<string,int> seenString;
        string patternChar = "";
        string patternString = "";
        
        
        for (char c : pattern) {
            if (seenChar.find(c) == seenChar.end()) {
                seenChar[c] = idChar;
                idChar++;
            }
            patternChar += to_string(seenChar[c]);
        }
        
        string word = "";
        str += ' ';
        for (int i=0; i<str.length(); i++) {
            char c = str[i];
            if (c == ' ') {
                                
                if (seenString.find(word) == seenString.end()) {
                    seenString[word] = idString;
                    idString++;
                }
                patternString += to_string(seenString[word]);
                
                
                word = "";
            } else {
                word += c;
            }
        }
        
        //cout<<patternChar<<endl;
        //cout<<patternString<<endl;

        if (patternChar == patternString) {
            return true;
        }
        return false;
        
    }
};