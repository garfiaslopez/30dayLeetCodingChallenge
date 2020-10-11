// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/teemo-attacking/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size() == 0) return 0;
        int totalTime = 0;
        for(int i=0; i<timeSeries.size()-1; i++) {
            totalTime += min(duration, timeSeries[i + 1] - timeSeries[i]);
        }
        return totalTime + duration;
    }
};
