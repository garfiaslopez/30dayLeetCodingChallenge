// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/delete-node-in-a-linked-list
//
// © Jose Garfias Lopez
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        // moving address memory from the actual to the next
        *node = *(node->next);
        
        // or manually moving
        //node->val = node->next->val;
        //node->next = node->next->next;
        
        /* iterating over nodes and replacing one by one.
        ListNode* tmp = node;
        ListNode* beforeLast;
        
        while(tmp != NULL) {
            if (tmp->next != NULL) {
                beforeLast = tmp;
                tmp->val = tmp->next->val;
                tmp = tmp->next;
            } else {
                tmp = NULL;
            }
        }
        beforeLast->next = NULL;
        
        */
    }
};