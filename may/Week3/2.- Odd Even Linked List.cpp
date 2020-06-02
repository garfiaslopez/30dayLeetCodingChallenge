// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !(head->next) || !(head->next->next)) { return head; }
        
        ListNode* node = head->next->next;
        ListNode* lastOdd = head;
        ListNode* lastEven = head->next;
        ListNode* firstEven = head->next;
        
        bool isOdd = true;        
        while(node != NULL) {           
            if (isOdd) {
                lastOdd->next = node;
                lastOdd = node;
            } else {
                lastEven->next = node;
                lastEven = node;
            }
            
            // step on the linkedList
            node = node->next;
            isOdd = !(isOdd); 
        }
        
        lastOdd->next = firstEven;
        lastEven->next = NULL;
        return head;
    }
};