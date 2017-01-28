#include <iostream>
#include
 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // O(M+N), recursive: 22.89%, ok
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;   // boundary conditions
        if(l2 == NULL) return l1;
        if(l1 -> val <= l2 -> val){
            l1 -> next = mergeTwoLists(l1 -> next, l2);
            return l1;
        }
        else{
            l2 -> next = mergeTwoLists(l1, l2 -> next);
            return l2;
        }
    }

    // O(M+N), iterative: 22.89%, ok
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode ret(0);       // bug: ListNode* ret = l
        ListNode* l = &ret;    // bug: ListNode* l
        while(l1 && l2){
            if(l1->val <= l2->val) {
                l->next = l1;
                l1 = l1->next;
            }
            else {
                l->next = l2;
                l2 = l2->next;
            }
            l = l->next;
        }
        if(l1) l->next = l1;
        if(l2) l->next = l2;
        return ret.next;
    }
};
