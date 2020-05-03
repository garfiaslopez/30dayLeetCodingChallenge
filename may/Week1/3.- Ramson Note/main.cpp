// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> noteMap;
        map<char,int> magazineMap;
        
        for (char letter : ransomNote) {
            if (noteMap[letter]) {
                noteMap[letter] += 1;
            } else {
                noteMap[letter] = 1;
            }
        }
        for (char letter : magazine) {
            if (magazineMap[letter]) {
                magazineMap[letter] += 1;
            } else {
                magazineMap[letter] = 1;
            }
        }
        
        map<char,int> :: iterator noteMapIt;
        for (noteMapIt=noteMap.begin(); noteMapIt != noteMap.end(); noteMapIt++) {            
            
             if (magazineMap.find(noteMapIt->first) == magazineMap.end() || magazineMap[noteMapIt->first] < noteMapIt->second) return false;
        }
        
        return true;
    }
};