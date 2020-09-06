// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.size() == 0) return 0;
    int max = 0;
    for (int i=0; i<prices.size()-1; i++) {
        if (prices[i] < prices[i+1]) {
            max += prices[i+1] - prices[i];
        }
    }
    return max;
}

int main() {
    vector<int> numbers;
    int n;
    while(cin>>n) {
        numbers.push_back(n);
    }
    cout<<maxProfit(numbers);
    return (0);
}
