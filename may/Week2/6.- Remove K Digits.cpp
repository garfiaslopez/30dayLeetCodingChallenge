// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {   
        int n = num.size();
        stack<char> maxStack;
        
        for (char c:num) {
            while(!maxStack.empty() && k>0 && maxStack.top() > c) {
                maxStack.pop();
                k--;
            }
            if (!maxStack.empty() || c != '0') {
                maxStack.push(c);
            }
        }
        
        while(!maxStack.empty() && k--) {
            maxStack.pop();
        }
        if (maxStack.empty()) {
            return "0";
        }
        
        while(!maxStack.empty()) {
            num[n-1] = maxStack.top();
            maxStack.pop();
            n--;
        }
        return num.substr(n);
    }
};