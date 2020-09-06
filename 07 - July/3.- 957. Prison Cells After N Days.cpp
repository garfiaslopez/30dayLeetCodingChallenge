// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/prison-cells-after-n-days/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    
    void print(vector<int> &a) {
        for (int i=0; i<a.size(); i++) {
            cout<<a[i]<<", ";
        }
        cout<<endl;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        
        vector<int> oldState(cells.size());
        copy(cells.begin(), cells.end(), oldState.begin());
        vector<int> newState(cells.size());
        copy(cells.begin(), cells.end(), newState.begin());

        int iter = (N%14);
        if (iter == 0) { iter = 14; };
        
        while(iter > 0) {
            for (int i=0; i<cells.size(); i++) {
                if (i == 0 || i == cells.size()-1) {
                    newState[i] = 0;
                } else if (oldState[i-1] == oldState[i+1]) {
                    newState[i] = 1;
                } else {
                    newState[i] = 0;                  
                }
            }
            print(newState);
            oldState = newState;
            iter--;
        }
        return newState;
    }
};