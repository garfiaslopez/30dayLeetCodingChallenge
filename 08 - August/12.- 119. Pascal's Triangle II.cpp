// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/pascals-triangle-ii/
//
// © Jose Garfias Lopez
//



class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> response;
                
        for (int i=0; i<=rowIndex; i++) {
            if (i == 0) {
                response.push_back({1});
            } else if (i == 1) {
                response.push_back({1,1});
            } else if (i >= 2) {
                int lastIndex = i-1;
                vector<int> newRow;rowIndex
                
                newRow.push_back(1);
                for (int j=0; j<=(response[lastIndex].size() - 2); j++) {
                    newRow.push_back(response[lastIndex][j] + response[lastIndex][j+1]);
                }
                newRow.push_back(1);
                
                response.push_back(newRow);
            }
        }
        
        return response[response.size()-1];
    }
};