// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/counting-elements/
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int countingNumbers(vector<int>& numbers) {
    map<int,int> needToFind;

    //populate map with numbers to find
    for (int i=0; i<numbers.size(); i++) {
        needToFind[numbers[i]] = 1;
    }
    int founds = 0;
    for(int i=0; i<numbers.size(); i++) {
        if (needToFind[numbers[i]+1] > 0) {
            founds++;
        }
    }
    return founds;
}

int main() {
    vector<int> numbers;
    int n;
    while(cin>>n) {
        numbers.push_back(n);
    }
    cout<<countingNumbers(numbers);
    return (0);
}