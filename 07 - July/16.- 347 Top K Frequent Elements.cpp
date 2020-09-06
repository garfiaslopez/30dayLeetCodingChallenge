// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/top-k-frequent-elements/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freqs;
        map<int,vector<int>> grouped;
        
        for (int n: nums) {
            if (freqs.find(n) == freqs.end()) {
                freqs[n] = 1;
            } else {
                freqs[n]++;
            }
        }
        for (auto it: freqs) {
            if (grouped.find(it.second) == grouped.end()) {
                grouped[it.second] = { it.first };
            } else {
                grouped[it.second].push_back(it.first);
            }
        }
        vector<int> answer;
        int times = 0;
        auto it = grouped.rbegin();
        for (it; it != grouped.rend(); it++) {
            for (int val: it->second) {
                if (times < k) {
                    times++;
                    answer.push_back(val);
                } else {
                    break;
                }
            }
        }
        
        return answer;
    }
};