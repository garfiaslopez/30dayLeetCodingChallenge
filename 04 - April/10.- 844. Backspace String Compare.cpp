// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/backspace-string-compare/
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

bool isSameStack(stack<char> stack1, stack<char> stack2) { 
    bool flag = true; 
    if (stack1.size() != stack2.size()) { 
        flag = false; 
        return flag; 
    } 
    while (stack1.empty() == false) { 
        if (stack1.top() == stack2.top()) { 
            stack1.pop(); 
            stack2.pop(); 
        } 
        else { 
            flag = false; 
            break; 
        } 
    } 
    return flag; 
}

bool backspaceCompare(string S, string T) {
    stack<char> compareStackS;
    stack<char> compareStackT;

    for (char c : S) {
        if (c == '#') {
            if (!compareStackS.empty()) {
                compareStackS.pop();
            }
        } else {
            compareStackS.push(c);
        }
    }

    for (char c : T) {
        if (c == '#') {
            if (!compareStackT.empty()) {
                compareStackT.pop();
            }
        } else {
            compareStackT.push(c);
        }
    }
    return isSameStack(compareStackS, compareStackT);
}

int main() {
    string a,b;
    cin>>a>>b;
    cout<<backspaceCompare(a,b);
    return(0);
}