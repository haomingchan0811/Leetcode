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
            if(nextNode->val == cur->val){
                cur->next = nextNode->next;
            }
            else cur = nextNode;
            nextNode = nextNode->next;
        }
        return head;
    }
};