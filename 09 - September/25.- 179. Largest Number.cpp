// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/largest-number/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    static bool comp(int a, int b) {
        string aStr = to_string(a);
        string bStr = to_string(b);
        return (aStr + bStr > bStr + aStr);
    }
    
    bool allZeros(string answer) {
        int count = 0;
        for (char c : answer) {
            if (c == '0') {
                count++;
            }
        }
        return answer.length() == count;
    }
    
    string largestNumber(vector<int>& nums) {
        string answer = "";
        sort(nums.begin(), nums.end(), comp);
        for (int n : nums) {
            answer += to_string(n);
        }
        
        if (allZeros(answer)) return "0";
        return answer;
    }
};