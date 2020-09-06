// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/k-closest-points-to-origin
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    double euclideanDistance(vector<int> point) {
        
        int x1 = 0;
        int y1 = 0;
        int x2 = point[0];
        int y2 = point[1];
        
        double x = x1 - x2;
        double y = y1 - y2;
        double dist;

        dist = pow(x, 2) + pow(y, 2);
        dist = sqrt(dist);                  

        return dist;
    }
    
    static bool comp(pair<double,int> &p1, pair<double,int> &p2) {
        return p1.first < p2.first;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<double,int>> pointsWithDistance;
        
        for (int i=0; i<points.size(); i++) {
            double distance = euclideanDistance(points[i]);
            pointsWithDistance.push_back(make_pair(distance, i));
        }
        
        sort(pointsWithDistance.begin(), pointsWithDistance.end(), comp);
        
        vector<vector<int>> result;
        for (int i=0; i<K; i++) {
            int index = pointsWithDistance[i].second;
            result.push_back(points[index]);
        }
        
        return result;
    }
};