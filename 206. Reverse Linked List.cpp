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
    // iterative: O(N) time, O(1) space, 45.71%, ok
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;  // bug: only one element, directly return.
        ListNode* next = head->next;
        ListNode* pre = NULL;
        head->next = pre;
        pre = head;
        head = next;
        while(head->next){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        head->next = pre;
        return head;
    }

    // iterative with more elegancy: 45.71%, ok
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        return pre; // bug: not return head
    }

    // (STUCK) recursive: 45.71%
    // O(N) time, key is to work backwards
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* nextNode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return nextNode;
    }

};
