// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int i=0; i<nums.size(); i++) {
        result ^= nums[i];
    }
    return result;
}

int main() {
    vector<int> numbers;
    int n;
    while(cin>>n) {
        numbers.push_back(n);
    }
    cout<<singleNumber(numbers);
    return (0);
}
