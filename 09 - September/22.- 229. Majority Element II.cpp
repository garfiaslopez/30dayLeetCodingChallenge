// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/majority-element-ii/
//
// © Jose Garfias Lopez
//


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /*
        Boyer-Moore Voting algotithm
        */
        
        int n = nums.size();
        
        if (n == 0 ) return {};
        
        int firstCandidate = nums[0];
        int secondCandidate = nums[0];
        int firstCount = 0;
        int secondCount = 0;
        
        for (int n: nums) {
            if (n == firstCandidate) {
                firstCount++;
            } else if(n == secondCandidate) {
                secondCount++;
            } else if (firstCount <= 0) {
                firstCandidate = n;
                firstCount = 1;
            } else if (secondCount <= 0) {
                secondCandidate = n;
                secondCount = 1;
            } else {          
                firstCount--;
                secondCount--;
            }
        }
        
        int firstTimes = 0;
        int secondTimes = 0;
        for (int n : nums) {
            if (n == firstCandidate) {
                firstTimes++;
            } else if (n == secondCandidate) {
                secondTimes++;
            }
        }
        
        //cout<<firstCandidate<<","<<firstCount<<"   |.   "<<secondCandidate<<","<<secondCount<<endl;
        
        vector<int> answer;
        if (firstTimes > n/3) {
            answer.push_back(firstCandidate);
        }
        if (secondTimes > n/3) {
            answer.push_back(secondCandidate);
        }
        
        return answer;
        
    }
};