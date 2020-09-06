// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/maximum-subarray/
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int max = INT_MIN, max_here = 0;
    for (int i=0; i<nums.size(); i++) {
        max_here = max_here + nums[i]; 
        if (max < max_here) {
            max = max_here; 
        }

        if (max_here < 0) {
            max_here = 0; 
        }
    } 
    return max;
}

int main() {
    vector<int> numbers;
    int n;
    while(cin>>n) {
        numbers.push_back(n);
    }
    cout<<maxSubArray(numbers);
    return (0);
}
