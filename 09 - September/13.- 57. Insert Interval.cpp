// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/combination-sum-iii/
//
// © Jose Garfias Lopez
//

//https://leetcode.com/problems/insert-interval/discuss/21669/Easy-and-clean-O(n)-C%2B%2B-solution
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        size_t i = 0;
        
        // Left part (no intersection with newInterval)
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            ++i;
        }
        
        // newInterval part (with or without merge)
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }
        res.push_back(newInterval);
        
        // Right part (no intersection with newInterval)
        while (i < intervals.size() && intervals[i][0] > newInterval[1]) {
            res.push_back(intervals[i]);
            ++i;
        }
        return res;
    }
};