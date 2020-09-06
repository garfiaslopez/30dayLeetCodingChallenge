// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/reorder-list/
//
// © Jose Garfias Lopez
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = NULL;
        while (head) {
            ListNode* next = head -> next;
            head -> next = cur;
            cur = head;
            head = next;
        }
        return cur;
    }
    
    void reorderList(ListNode* head) {        
        ListNode* current = head;
        
        
        while(current != NULL) {
            
            ListNode* nextEl = current->next;
            if (nextEl) {
                ListNode* newEl = reverseList(nextEl);
                current->next = newEl;
                current = newEl;
            } else {
                
                current = NULL;
            }
        }
        
        
        
        
    }
};
