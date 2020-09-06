// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/partition-labels/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char,int> lastSeen;
        int n = S.length();
        for (int i=n-1; i>=0; i--) {
            char val = S[i];
            if (lastSeen.find(val) == lastSeen.end()) {
                lastSeen[val] = i;
            }
        }
        
        vector<int> answer;
        
        int maxIndexWindow = INT_MIN;
        int lowIndexWindow = -1;
        for (int i=0; i<n; i++) {
            char actualVal = S[i];
            int lastSeenIndex = lastSeen[actualVal];
            maxIndexWindow = max(maxIndexWindow, lastSeenIndex);
            
            if (i == maxIndexWindow) {
                int size = maxIndexWindow - lowIndexWindow;
                answer.push_back(size);
                lowIndexWindow = i;
                maxIndexWindow = INT_MIN;
            }
        }
        
        return answer;
    }
};