// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/sort-array-by-parity/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    
    static bool comp (int a, int b) {
        return (a%2 == 0) > (b%2 ==0);
    }
    
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> sorted(A);
        sort(sorted.begin(), sorted.end(), comp);
        return sorted;
    }
};