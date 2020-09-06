// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/first-unique-number/
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class FirstUnique {
    public :
    bool calculateFirst = true;
    queue<int> firstSeen;
    unordered_map<int, int> alreadySeen;
    int lastFirstUnique = -1;
    
    FirstUnique(vector<int> &nums){
        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);
        }
    }
    int showFirstUnique() {
        if (calculateFirst){
            lastFirstUnique = -1;
            while (!firstSeen.empty()){
                int unique = firstSeen.front();
                int seen = alreadySeen[unique];
                if (seen <= 1){
                    lastFirstUnique = unique;
                    break;
                } else {
                    firstSeen.pop();
                }
            }
        }
        calculateFirst = false;
        return lastFirstUnique;
    }
    void add(int value) {
        calculateFirst = true;
        if (alreadySeen.find(value) == alreadySeen.end()) {
            firstSeen.push(value);
            alreadySeen[value] = 1;
        } else {
            alreadySeen[value] += 1;
        }
    }
};