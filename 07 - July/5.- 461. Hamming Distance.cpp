// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/hamming-distance/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    int hammingDistance(int x, int y) {
        int bitsDiff = x^y;
        int count = 0;
        while(bitsDiff) {
            if ((bitsDiff & 1) == 1) {
                count++;
            }
            bitsDiff = bitsDiff>>1;
        }
        return count;
    }
};