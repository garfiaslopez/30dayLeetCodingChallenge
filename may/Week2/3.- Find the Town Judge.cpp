// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int,int> trustCounter;
        unordered_map<int,int> trustIn;
        
        for (vector<int> relation : trust) {
            int a = relation[0];
            int b = relation[1];
            
            trustIn[a] = b;
            trustCounter[b]++;
        }
        
        for (int i=1; i<=N; i++) {
            if (trustIn.find(i) == trustIn.end()) {
                if (trustCounter[i] == N-1) {
                    return i;
                }
            }
        }
        return -1;
    }
};