// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/sort-characters-by-frequency
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

bool compare (const pair<char,int> &a, const pair<char,int> &b) {
    return a.second > b.second;
}

class Solution {

public:
    string frequencySort(string s) {
        unordered_map<char, int> frequencies;
        
        for (char c: s) {
            if (frequencies.find(c) == frequencies.end()) {
                frequencies[c] = 1;
            } else {
                frequencies[c]++;
            }
        }
        
        vector<pair<char,int>> array;
        for (auto it: frequencies) {
            array.push_back(make_pair(it.first,it.second));
        }
        sort(array.begin(), array.end(), compare);
        
        string newString = "";
        for (pair<char,int> letter: array) {
            // cout<<"l: "<<letter.first<<"  f: "<<letter.second<<endl;
            for (int i=0; i<letter.second; i++) {
                newString += letter.first;
            }    
        }
        return newString;
    }
};