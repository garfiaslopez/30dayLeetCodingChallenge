// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());
            int firstRock = stones.back();
            stones.pop_back();
            int secondRock = stones.back();
            stones.pop_back();
            if (firstRock != secondRock) {
                stones.push_back(firstRock - secondRock);
            }
        }
        if (stones.size() == 1) {
            return stones[0];
        }
        return 0;
    }
};