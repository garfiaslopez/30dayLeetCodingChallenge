// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int kadanes (vector<int>& A, bool inverted) {
        int soFar = INT_MIN;
        int endingHere = 0;
        for (int i=0;i<A.size(); i++) {
            int actualValue = inverted ? -(A[i]) : A[i];
            endingHere = endingHere + actualValue; 
            if (soFar < endingHere) {
                soFar = endingHere;
            }
            if (endingHere < 0) {
                endingHere = 0;
            }
        }
        return soFar;
    }
    
    int maxSubarraySumCircular(vector<int>& A) {
        
        int totalSum = 0;
        int negatives = 0;
        int maxNumber = INT_MIN;
        for (int i=0;i<A.size(); i++) {
            if (A[i] < 0) {
                negatives++;
            }
            totalSum += -(A[i]);
            maxNumber = max(maxNumber, A[i]);
        }
        int maxK = kadanes(A, false);
        int maxKNegative = kadanes(A, true);
        int maxKInverted = -(totalSum) - (-maxKNegative);
        
        if (negatives == A.size()) {
            return maxNumber;
        }
        
        return max(maxK, maxKInverted);
    }
};