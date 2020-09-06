// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/arranging-coins/
//
// © Jose Garfias Lopez
//



class Solution {
public:
    
    int arrangeCoins(int n) {
        int temp = n;
        int step = 0;
        
        while(temp >= 0) {
            step++;
            temp -= step;
        }
        return step-1;
    }
};