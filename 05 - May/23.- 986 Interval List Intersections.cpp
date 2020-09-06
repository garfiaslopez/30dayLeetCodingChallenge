// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/interval-list-intersections
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

/*
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        vector<pair<int,bool>> intersection(1010,make_pair(0,false));
        
        if (A.size() == 0 || B.size() == 0) return {};
        
        for (vector<int> range : A) {
            for (int i=range[0]; i<=range[1]; i++) {
                intersection[i].first++;
            }
            intersection[range[1]].second = true;
        }
        
        for (vector<int> range : B) {
            for (int i=range[0]; i<=range[1]; i++) {
                intersection[i].first++;
            }
            intersection[range[1]].second = true;
        }
        
        bool started = false;
        vector<vector<int>> result;
        int firstIndex = 0;
        
        for (int i=0; i<intersection.size();i++) {
            if(intersection[i].first == 2) {
                
                if (intersection[i].second == false) {
                    if (!started) {
                        firstIndex = i;
                        started = true;
                    }
                } else {
                    if (!started) {
                        result.push_back({i, i});
                    } else {
                        started = false;
                        result.push_back({firstIndex, i});
                    }
                }
                
            } else {
                if (started) {
                    started = false;
                    result.push_back({firstIndex, i-1});
                }
            }
        }
        return result;
    }
};

*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int Aptr=0, Bptr=0;
        int sizeA = A.size();
        int sizeB = B.size();
        vector<int> temp(2);
        
        while(Aptr<sizeA && Bptr<sizeB) {
            if (B[Bptr][0] <= A[Aptr][1] && A[Aptr][0] <= B[Bptr][1]) {
                temp[0] = max(A[Aptr][0], B[Bptr][0]);
                temp[1] = min(A[Aptr][1], B[Bptr][1]);
                res.push_back(temp);
            }
            if (A[Aptr][1] > B[Bptr][1]) {
                Bptr++;
            } else {
                Aptr++;
            }
        }
        return res;
    }
};

