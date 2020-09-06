// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/single-number-ii/
//
// © Jose Garfias Lopez
//


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        int ones = 0;
        int twos = 0;
        for(auto x: nums) {
            ones = (ones^x) & (~twos);
            twos = (twos^x) & (~ones);
        }
        return ones;
        */
        
        /*
        unordered_set<int,int> freq;
        for(int x:nums) {
            if (freq.find(x) != freq.end()) {
                freq[x] = 1;
            } else {
                freq[x]++;
            }
        }
        
        for (auto it: freq) {
            if (it.second == 1) {
                return it.first;
            }
        }
        
        
        //
        int a,b = 0;
        for (int x: nums) {
            a = (a^x) & (~b);
            b = (b^x) & (~a);
        }
        return a;
        */
        
        //https://leetcode.com/problems/single-number-ii/discuss/43295/Detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers 
        int x1 = 0, x2 = 0, mask = 0;
         
        for (int i : nums) {
            x2 ^= x1 & i;
            x1 ^= i;
            mask = ~(x1 & x2);
            x2 &= mask;
            x1 &= mask;
        }

        return x1;
    }
};