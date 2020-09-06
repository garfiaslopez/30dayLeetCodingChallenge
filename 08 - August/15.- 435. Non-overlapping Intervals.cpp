// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/non-overlapping-intervals/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    
    static bool comp(vector<int> a, vector<int> b) {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        
        int count = 0, last_included = 0;
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] < intervals[last_included][1]) { // Overlap
                count++;
            } else {
                last_included = i;
            }
        }
        
        return count;
    }
};