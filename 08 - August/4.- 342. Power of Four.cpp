// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/power-of-four/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    bool isPowerOfFour(int num) {
        float tmp = num;
        while(tmp>1){
         tmp = tmp / 4;
        }
        if (tmp == 1.0) return true;
        return false;
    }
};