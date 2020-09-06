// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/largest-time-for-given-digits/
//
// © Jose Garfias Lopez
//

class Solution {    
public:    
    bool isValidTime(vector<int> &A) {
        bool validHour = (A[0] <= 1 && A[1] <= 9) || (A[0] == 2 && A[1] <= 3);
        bool validMins = (A[2] <= 5 && A[3] <= 9);
        return validHour && validMins;
    }
    
    string vectorNumToString(vector<int> &A) {
       return to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
    }
    
    string largestTimeFromDigits(vector<int>& A) {
        string maxTime = "";
        sort(A.begin(), A.end());
        
        do {
            if (isValidTime(A)) {
                string timeStr = vectorNumToString(A);
                if (timeStr > maxTime) {
                    maxTime = timeStr;
                }
            }
            
        } while(next_permutation(A.begin(), A.end()));
        
        return maxTime;
    }
};