// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/permutation-sequence/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    string getPermutation(int n, int k) {
        string numbers = "";
        for (int i=1; i<=n; i++) {
            char c = i + '0';
            numbers += c;
        }
        while(k>1) {
            next_permutation(numbers.begin(), numbers.end());
            k--;
        }
        return numbers;
    }
};