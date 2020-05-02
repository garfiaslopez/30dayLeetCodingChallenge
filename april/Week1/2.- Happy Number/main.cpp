// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> getDigits(int n) {
    vector<int> digits;
    int temp = n;
    while(temp % 10 != temp) {
        int digit = temp%10;
        digits.push_back(digit);
        temp = temp / 10;
    }
    digits.push_back(temp);
    return digits;
}

bool isHappy(int n) {
    map<int, bool> seen;
    bool nextCalculation = true;
    int number = n;
    int isHappyNumber = false;
    while (nextCalculation) {
        int resultOfSum = 0;
        vector<int> digits = getDigits(number);
        for (int i=0; i<digits.size(); i++) {
            int actualNumber = digits[i];
            resultOfSum += (actualNumber * actualNumber);
        }
        if (resultOfSum == 1) {
            nextCalculation = false;
            isHappyNumber = true;
        } else {
            if (!seen[resultOfSum]) {
                seen[resultOfSum] = true;
                number = resultOfSum;
            } else {
                nextCalculation = false;
            }
        }
    }
    return isHappyNumber;
}

int main() {
    int number;
    cin>>number;
    cout<<isHappy(number)<<endl;
    return (0);
}
