// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/h-index-ii/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    int hIndex(vector<int>& citations) {
         // binary search 
        int left = 0;
        int right = citations.size()-1;

        while(left<=right) {
            int mid = left + (right - left) / 2 ;
            int invertedI = citations.size() - mid;
            
            if (citations[mid] == invertedI) {
                return invertedI;
            } else if (citations[mid] > invertedI) {
                right = mid - 1;
            } else if (citations[mid] < invertedI) {
                left = mid + 1;
            }
        }

        return citations.size() - left;
    }
};