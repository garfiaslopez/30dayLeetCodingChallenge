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

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        
        map<int,int> countMap;
        countMap[0] = 1;
        
        int sum=0;
        int result=0;
        
        for (int i=0;i<nums.size();i++) {
            sum += nums[i];
            if (countMap.find(sum-k) != countMap.end()) {
                result += countMap[sum-k];
            }
            int nextValue = 0;
            if (countMap.find(sum) != countMap.end()) {
                nextValue = countMap[sum];
            }
            
            countMap[sum] = nextValue + 1;
        }
        
        return result;
    }
};