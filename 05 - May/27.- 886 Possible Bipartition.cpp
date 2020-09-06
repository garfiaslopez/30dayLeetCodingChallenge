// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/possible-bipartition
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    /*
    unordered_map <int,bool> firstGroup;
    unordered_map <int,bool> secondGroup;
    unordered_map <int,int> combined;

    int searchIn(int a) {
        if (firstGroup.find(a) != firstGroup.end()) return 1;
        if (secondGroup.find(a) != secondGroup.end()) return 2;
        return 0;
    }*/
    
    bool isBipartite(vector<vector<int>> &adj, int N, int node, vector<int> &color) {
        // Using BFS, process graph
        
        queue<int> q;
        q.push(node);
        color[node] = 1;
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int ele: adj[curr]) {
                if (color[ele] == color[curr]) { // Odd - cycle 
                    return false;
                }
                if (color [ele] == -1) { //unvisited Node
                    color[ele] = 1-color[curr];
                    q.push(ele);
                }
            }
        }
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(N+1);
        
        for (vector<int> pair: dislikes) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }
        vector<int> color(N+1, -1);
        for (int i=1; i<=N; i++) {
            if (color[i] == -1) {
                if (!isBipartite(adj,N,i,color)) {
                    return false;
                }
            }
        }
        return true;
            
            
            
        /* tried whith maps
        for (vector<int> pair : dislikes) {
            int a = pair[0];
            int b = pair[1];
            
            int aisInMap = searchIn(a);
            if (aisInMap) {
                if (aisInMap == 1) {
                    secondGroup[b] = true;
                } else if (aisInMap == 2) {
                    firstGroup[b] = true;
                }
            } else {
                int bisInMap = searchIn(b);
                if (bisInMap) {
                    if (bisInMap == 1) {
                        secondGroup[a] = true;
                    } else if (bisInMap == 2) {
                        firstGroup[a] = true;
                    }
                } else {
                    firstGroup[b] = true;
                    secondGroup[a] = true;
                }

            }   
        }
        
        
        // combine
        for (auto it : firstGroup) {
            if (combined[it.first]) {
                combined[it.first]++;
            } else {
                combined[it.first] = 1;
            }
        }
        for (auto it : secondGroup) {
            if (combined[it.first]) {
                combined[it.first]++;
            } else {
                combined[it.first] = 1;
            }
        }
        
        // check
        for (auto it : combined) {
            cout<<"key: "<<it.first<<" val: "<< it.second<< endl;
            if (it.second >= 2) {
                return false;
            }
        }
        
        return true;       
        */
        
        
        
    }
};