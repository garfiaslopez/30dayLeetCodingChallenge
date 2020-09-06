// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/single-element-in-a-sorted-array
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    bool isUnique(vector<int>& nums, int m) {
        if (m == 0 && nums[m] != nums[m+1]) return true;
        if (m == nums.size()-1 && nums[m] != nums[m-1]) return true;
        if (nums[m] != nums[m-1] && nums[m] != nums[m+1]) return true;
        return false;
    }
    
    bool goToLeft(vector<int>& nums, int m) {
        bool middleIsOdd = m%2 != 0;
        
        if (middleIsOdd) {
            if (nums[m] == nums[m-1]) {
                return false;
            }
        } else {
            if (nums[m] == nums[m+1]) {
                return false;
            }
        }
        
        return true;
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        
        if (nums.size() < 2) return nums[0];
        
        int left = 0;
        int right = nums.size()-1;
        
        while(left <= right) {
            int middle = left + (right - left) / 2;
            
            cout<<"middle: "<<middle<<endl;
            
            if (isUnique(nums, middle)) {
                return nums[middle];
            } else if (goToLeft(nums,middle)) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return 0;
    }
};