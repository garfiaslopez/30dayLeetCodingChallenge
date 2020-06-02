// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map <char, pair<int,int> > freqMap;
        
        for (int i=0; i<s.length(); i++) {
            if (freqMap.find(s[i]) != freqMap.end()) {
                pair<int,int> data = freqMap[s[i]];
                freqMap[s[i]] = make_pair(data.first+1,data.second);
            } else {
                freqMap[s[i]] = make_pair(1,i);
            }
        }
        unordered_map <char, pair<int,int> >::iterator freqMapIt;
        int minIndex = INT_MAX;
        for (freqMapIt = freqMap.begin(); freqMapIt != freqMap.end(); freqMapIt++) {
            if (freqMapIt->second.first == 1) {
                minIndex = min(minIndex, freqMapIt->second.second);
            }
        }
        return minIndex == INT_MAX ? -1 : minIndex;
    }
};