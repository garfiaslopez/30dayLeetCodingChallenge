// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/reverse-bits/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    uint32_t reverseBits(uint32_t num) {
        unsigned int count = sizeof(num) * 8 - 1; // total of bits
        unsigned int reverse_num = num;
      
        num >>= 1; // shift to right
        while(num) { 
            reverse_num <<= 1;        
            reverse_num |= num & 1; 
            num >>= 1; 
            count--; 
        } 
        reverse_num <<= count; 
        return reverse_num; 
    }
};