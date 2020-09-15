// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/bulls-and-cows/
//
// © Jose Garfias Lopez
//

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        unordered_map<char, int> secretMap;
        unordered_set<int> used;
        
        for (char c : secret) {
            if (secretMap.find(c) == secretMap.end()) {
                secretMap[c] = 1;
            } else {
                secretMap[c] += 1;
            }
        }
        
        int bulls = 0;
        int cows = 0;
        
        for (int i=0; i<n; i++) {
            char c = guess[i];
            if (secret[i] == guess[i]) {
                bulls++;
                secretMap[c] -= 1;
                used.insert(i);
            }
        }
        
        for (int i=0; i<n; i++) {
            char c = guess[i];
            if (used.find(i) == used.end() && secretMap.find(c) != secretMap.end()) {
                if (secretMap[c] > 0) {
                    cows++;
                    secretMap[c] -= 1;
                }
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};