// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/angle-between-hands-of-a-clock/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    double angleClock(int hour, int minutes) {
        unordered_map<int,double> hourToMin;
        
        hourToMin[12] = 0.0;
        for (int i=1; i<12; i++) {
            hourToMin[i] = i * 5.0;
        }
        
        double minsInHour = hourToMin[hour];
        double hourOffset = (double(minutes) * 5.0) / 60.0;
        double minsBetweenHands = abs(double(minutes) - (minsInHour + hourOffset));
        double minsOutsideHands = 60 - minsBetweenHands;

        return min(minsBetweenHands * 6, minsOutsideHands * 6);
    }
};