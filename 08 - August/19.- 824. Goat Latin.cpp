// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/goat-latin/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    
    bool isStartingVowel(string Str) {
        if (Str.length() > 0) {
            char c = Str[0];
            return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                   c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
        }
        return false;
    }
    
    string convertToGoat(string Str, int wordIndex) {
        string strGoat = "";
        
        if (isStartingVowel(Str)) {
            strGoat = Str + "ma";
        } else {
            char firstLetter = Str[0];
            strGoat = Str.substr(1,Str.length()) + firstLetter + "ma";
        }
        
        for (int i=0; i<wordIndex; i++) {
            strGoat += 'a';
        }
        
        return strGoat;
    }
    
    string toGoatLatin(string S) {
        
        string newString = "";
        char delimiter = ' ';
        string stringPart;
        stringstream ss(S);
        int wordIndex = 1;
        
        while(getline(ss, stringPart, delimiter)) {
            newString += convertToGoat(stringPart, wordIndex) + " ";
            wordIndex++;
        }
        newString.erase(newString.end() -1, newString.end());
        
        return newString;
    }
};