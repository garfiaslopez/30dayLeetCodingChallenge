// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/insert-delete-getrandom-o1/
//
// © Jose Garfias Lopez
//


class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_set<int> data;
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (data.find(val) == data.end()) {
            data.insert(val);
            return true;
        } else {
            return false;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (data.find(val) != data.end()) {
            data.erase(val);
            return true;
        } else {
            return false;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int size = data.size();
        if (size > 0) {
            int randElement = rand()%size;
            auto it = data.begin();
            while(randElement--) {
                it++;
            }
            return (*it);
        }
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */