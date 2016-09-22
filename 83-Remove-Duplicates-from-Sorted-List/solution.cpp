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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        ListNode* nextNode = cur->next;
        while(cur != NULL && nextNode != NULL){
            while(nextNode->val == cur->val){
                nextNode = nextNode->next;
            }
            cur->next = nextNode;
            cur = nextNode;
            nextNode = cur->next;
        }
        return head;
    }
};