// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    unordered_map<char, int> pFreq;
    unordered_map<char, int> sFreq;

    bool isAnagram(int i) {
        for (auto it: pFreq) {
            char key = it.first;
            int value = it.second;
            
            if (sFreq.find(key) == sFreq.end()) return false;
            if (sFreq[key] != value) return false;
        }
        return true;
    }
    
    void generateFreq(unordered_map<char, int> &a, string b) {
        for (char c : b) {
            if (a[c]) {
                a[c]++;
            } else {
                a[c] = 1;
            }
        }
    }
    
    vector<int> findAnagrams(string s, string p) {
        if (s.length() < p.length()) return {};
        
        generateFreq(sFreq, s.substr(0, p.length()));
        generateFreq(pFreq, p);
              
        vector<int> indexes;
        int lastIndex = s.length() - p.length();
        for (int i=0; i<=lastIndex; i++) {
            
            // decrement freq of past char in sFreq
            // increment freq of next char in sFreq
            if (i>0) {
                sFreq[s[i-1]]--;
                char where = s[i+p.length()-1];
                if (sFreq[where]) {
                    sFreq[where]++;
                } else {
                    sFreq[where] = 1;
                }
            }
            
            if (isAnagram(i)) {
                indexes.push_back(i);
            }
        }
        return indexes;
    }
};