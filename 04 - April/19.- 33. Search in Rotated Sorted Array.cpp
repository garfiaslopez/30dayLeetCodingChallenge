// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/search-in-rotated-sorted-array/
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() <= 0) return -1;
        
        int pivot = 0;
        
        int left = 0;
        int right = nums.size()-1;
        
        while(left < right) {
            int mid = left + (right-left)/2;
            
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        pivot = left;
        left = 0;
        right = nums.size()-1;
        
        if (target >= nums[pivot] && target <= nums[right]) {
            left = pivot;
        } else {
            right = pivot;
        }
        
        int foundAtIndex = -1;
        
        while(left <= right) {
            int mid = left + (right-left)/2;
            
            if (nums[mid] == target) {
                foundAtIndex = mid;
                break;
            } else if(target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            } 
        }
        
        return foundAtIndex;
    }
};  