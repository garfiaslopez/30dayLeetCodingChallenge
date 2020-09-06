// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/random-pick-with-weight/
//
// © Jose Garfias Lopez
//



class Solution {
     vector<int> accumulate;
public:
    Solution(vector<int>& w) {
        int sum = 0;
        for (int el: w) {
            sum += el;
            accumulate.push_back(sum);
        }
    }
    
    int pickIndex() {
        int random = rand() % accumulate.back();
        return upper_bound(accumulate.begin(),accumulate.end(), random) - accumulate.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */