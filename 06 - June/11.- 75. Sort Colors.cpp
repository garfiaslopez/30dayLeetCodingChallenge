// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/sort-colors/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freq(3,0);
        for (int n: nums) {
            freq[n]++;
        }
        int currentIndex = 0;
        for (int i=0; i<3; i++) {
            for (int j=0; j<freq[i]; j++) {
                nums[currentIndex] = i;
                currentIndex++;
            }
        }
    }
};