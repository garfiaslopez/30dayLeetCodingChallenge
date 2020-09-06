// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/remove-linked-list-elements/
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

/*
ListNode** cur = &head;
while(*cur) {
    if((*cur)->val == val) {
        (*cur) = (*cur)->next;
    } else {
        cur = &((*cur)->next);
    }
}
return head;

*/

/*
class Solution {
public:
    
    ListNode* nextNotEqual(ListNode* node) {
        int val = node->val;
        ListNode * current = node;
        while(current != NULL && current->val == val) {
            current = current->next;
        }
        return current;
    }
    
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* start = head;
        ListNode* tail = NULL;
        ListNode* current = head;
        
        while(current != NULL) {
            if(current->val == val) {
                if (tail) {
                    ListNode* nextValid = nextNotEqual(current);
                    tail->next = nextValid;
                    tail = nextValid;
                    if (nextValid) {
                        current = nextValid->next;
                    } else {
                        current = NULL;
                    }
                } else {
                    current = current->next;
                    start = current;
                }
            } else {
                tail = current;
                current = current->next;
            }
        }
        return start;
    }
};

*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode** cur = &head;
        while(*cur) {
            if((*cur)->val == val) {
                (*cur) = (*cur)->next;
            } else {
                cur = &((*cur)->next);
            }
        }
        return head;
    }
};

// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/remove-linked-list-elements/
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

/*
ListNode** cur = &head;
while(*cur) {
    if((*cur)->val == val) {
        (*cur) = (*cur)->next;
    } else {
        cur = &((*cur)->next);
    }
}
return head;

*/

/*
class Solution {
public:
    
    ListNode* nextNotEqual(ListNode* node) {
        int val = node->val;
        ListNode * current = node;
        while(current != NULL && current->val == val) {
            current = current->next;
        }
        return current;
    }
    
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* start = head;
        ListNode* tail = NULL;
        ListNode* current = head;
        
        while(current != NULL) {
            if(current->val == val) {
                if (tail) {
                    ListNode* nextValid = nextNotEqual(current);
                    tail->next = nextValid;
                    tail = nextValid;
                    if (nextValid) {
                        current = nextValid->next;
                    } else {
                        current = NULL;
                    }
                } else {
                    current = current->next;
                    start = current;
                }
            } else {
                tail = current;
                current = current->next;
            }
        }
        return start;
    }
};

*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode** cur = &head;
        while(*cur) {
            if((*cur)->val == val) {
                (*cur) = (*cur)->next;
            } else {
                cur = &((*cur)->next);
            }
        }
        return head;
    }
};

