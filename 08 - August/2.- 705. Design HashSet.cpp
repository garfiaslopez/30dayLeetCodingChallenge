// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/design-hashset/
//
// © Jose Garfias Lopez
//


class MyHashSet {
    
    int buckets = 1000;
    list<int> table [1000];
    
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        buckets = 1000;
    }
    
    int hashFunc(int key) {
        return key % this->buckets;
    }
    
    void add(int key) {
        int index = hashFunc(key);
        table[index].push_back(key);
    }
    
    void remove(int key) {
        int index = hashFunc(key);
        
        bool removedAll = false;
        list<int>::iterator it;

        while(!removedAll) {
            for (it=table[index].begin(); it != table[index].end(); it++) {
                if (*it == key) {
                    break;
                }
            }

            if (it != table[index].end()) {
                table[index].erase(it);
            } else {
                removedAll= true;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index = hashFunc(key);
        list<int>::iterator it;
        
        for (it=table[index].begin(); it != table[index].end(); it++) {
            if (*it == key) {
                break;
            }
        }
        
        if (it != table[index].end()) {
            return true;
        }
        
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */