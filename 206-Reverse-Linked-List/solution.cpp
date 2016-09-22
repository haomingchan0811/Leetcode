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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = NULL;
        while(cur != NULL){
            ListNode* nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }
        return prev;
    }
};