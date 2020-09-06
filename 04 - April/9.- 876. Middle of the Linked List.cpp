// compile & run:     g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://leetcode.com/problems/middle-of-the-linked-list/
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <math.h>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* middleNode(ListNode* head) {
    int tam = 0;
    ListNode* tmp = head;
    while(tmp != NULL) {
        tam++;
        tmp = tmp->next;
    }
    int middle = 0;        
    if(tam%2 == 0){
        middle = tam/2;
    } else {
        middle = ceil(tam/2);
    }
    tmp=head;
    while(middle--) {
        tmp = tmp->next;
    }
    return tmp;
}