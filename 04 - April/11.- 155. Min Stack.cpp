// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/min-stack/
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    
    stack<int> mainStack;
    stack<int> minStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        mainStack.push(x);
        
        if (minStack.empty()) {
            minStack.push(x);
        } else {
            int actualMin = minStack.top();
            if (x <= actualMin) {
                minStack.push(x);
            }
        }
    }
    
    void pop() {
        int valueToPop = mainStack.top();
        mainStack.pop();
        
        if (valueToPop == minStack.top()) {
            minStack.pop();
        }       
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */