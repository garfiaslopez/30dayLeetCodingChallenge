// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/power-of-two/
//
// © Jose Garfias Lopez
//



class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        while(n != 1) {
            if (n%2 != 0) {
                return false;
            }
            n /= 2;
        }
        return true;
    }
};