// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int actualIndex = 0;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i] != 0) {
            nums[actualIndex] = nums[i];
            actualIndex++;
        }
    }
    for (int i=actualIndex; i<nums.size(); i++) {
        nums[i] = 0;
    }
}

int main() {
    vector<int> numbers;
    int n;
    while(cin>>n) {
        numbers.push_back(n);
    }
    moveZeroes(numbers);
    for (int i=0; i<numbers.size();i++) {
        cout<<numbers[i]<<", ";
    }
    return (0);
}
