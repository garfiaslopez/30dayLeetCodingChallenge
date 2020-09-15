// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/combination-sum-iii/
//
// © Jose Garfias Lopez
//


class Solution {
public:
    vector<vector<int>> ans;
    
    void f(vector<int>& cur, int cnum, int k, int n) {
        if(n < 0 || cur.size() > k) return;
        if(n == 0 && cur.size() == k) {
            ans.push_back(cur);
            return;
        }
        
        for(int i=cnum; i<=9; ++i) {
            cur.push_back(i);
            f(cur, i+1, k, n-i);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur;
        f(cur, 1, k, n);
        return ans;
    }
};