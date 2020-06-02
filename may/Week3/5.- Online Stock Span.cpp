// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

class StockSpanner {
public:
    vector<int> prices;
    StockSpanner() {
        
    }
    
    int next(int price) {
        prices.push_back(price);
        
        int consecutives = 0;
        for (int i=prices.size()-1; i>=0; i--) {
            if (price >= prices[i]) {
                consecutives++;
            } else {
                break;
            }
        }
        
        return consecutives;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */