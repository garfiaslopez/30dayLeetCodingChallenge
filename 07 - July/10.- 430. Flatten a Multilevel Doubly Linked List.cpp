// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:  https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
//
// © Jose Garfias Lopez
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    Node* flatten(Node* head) {
        
        stack<Node*> toVisit;
        Node* current = head;
        Node* tail = head;
        
        while(current != NULL) {
            
            if (current->child != NULL) {
                
                if (current->next != NULL) {
                    current->next->prev = NULL;
                    toVisit.push(current->next);
                }
                
                current->next = current->child;
                current->child->prev = current;
                current->child = NULL;
            }
            
            if (current->next == NULL) {
                tail = current;
            }
            current = current->next;
        }
        
        while(!toVisit.empty()) {
            Node* stackNode = toVisit.top();
            toVisit.pop();
            
            while (stackNode != NULL) {
                tail->next = stackNode;
                stackNode->prev = tail;
                
                tail = stackNode;
                stackNode = stackNode->next;
            }
            
        }
        
        return head;
    }
};