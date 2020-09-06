// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/course-schedule
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    bool dfs(vector<vector<int>> &adj, vector<int> &visited, int current) {
        
        if (visited[current] == 2) {
            return true;
        }
        
        visited[current] = 2;
        
        for (int i=0; i<adj[current].size(); i++) {
            if (visited[adj[current][i]] != 1) {
                if (dfs(adj, visited, adj[current][i])) {
                    return true;
                }
            }
        }
        visited[current] = 1;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj (numCourses, vector<int>());
        for (vector<int> vertex: prerequisites) {
            int u = vertex[0];
            int v = vertex[1];
            adj[u].push_back(v);
        }
        
        vector<int> visited(numCourses, 0);
        
        for (int i=0; i<numCourses; i++) {
            if (visited[i] == 0) {
                if (dfs(adj, visited, i)) {
                    return false;
                }
            }
        }      
        return true;
    }
};  