// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/plus-one/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    
    vector<int> plusOne(vector<int>& digits) {
        
        vector<int> result(digits.size());
        int carry = 0;
        int n = digits.size();
        
        for (int i=n-1; i>=0; i--) {
            int sumResult = digits[i] + carry;
            if (i == n-1) { sumResult += 1; }
            result[i] = sumResult%10;
            if (sumResult > 9) {
                carry = sumResult/10;
            } else {
                carry = 0;
            }
        }
        
        if (carry > 0) {
            result.insert(result.begin(), carry);
        }
        
        return result;
    }
};