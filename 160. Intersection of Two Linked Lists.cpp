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
    // hashtable: O(M+N)time, O(M) or O(N) sapce, 2.87%
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        set<ListNode*> flag;
        while(headA){
          flag.insert(headA);
          headA = headA->next;
        }
        while(headB){
            if(flag.count(headB))
                return headB;
            headB = headB->next;
        }
        return NULL;
    }

    // hashtable: O(M+N), 31.76%, ok
    // trick: offset the length difference with only two iteration
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode* A = headA;
        ListNode* B = headB;
        //if a & b have different len, then we will stop the loop after second iteration when A = B = NULL
        while(A != B){
        	// at the end of first iteration, reset to the head of another linkedlist to counteract the length difference
            A = A == NULL? headB : A->next;
            B = B == NULL? headA : B->next;
        }
        return A;
    }
};
