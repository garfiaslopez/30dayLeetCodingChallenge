// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/sequential-digits/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    
    int countDigits(int num) {
        int count = 0;
        while(num > 0) {
            count++;
            num /= 10;
        }
        return count;
    }
    
    bool isInRange(int low, int high, int num) {
        return num >= low && num <= high;
    }
    
    void appendNumbersOfSize(int low, int high, int size, vector<int> &answer) {
        vector<int> fromNumbers = { 1,2,3,4,5,6,7,8,9 };
        
        for (int i=0; i<=fromNumbers.size() - size; i++) {
            
            int num = 0;
            for (int j=i; j<(i+size); j++) {
                num = num * 10 + fromNumbers[j];
            }
            
            if (isInRange(low, high, num)) {
                answer.push_back(num);
            }
        }
        
    }
    
    vector<int> sequentialDigits(int low, int high) {
                
        vector<int> answer;
        int lowDigits = countDigits(low);
        int highDigits = countDigits(high);
        
        for (int i=lowDigits; i<=highDigits; i++) {
            if (i <= 9) {
                appendNumbersOfSize(low, high, i, answer);
            }
        }
        return answer;
    }
};