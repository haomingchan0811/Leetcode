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
    // Two pass: O(N)time, O(1)space, 7.14%
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0, cnt = 0;
        ListNode* dummy = head;
        while(head){
            len++;
            head = head->next;
        }
        // bug test case: [1,2], n=2, delete head
        if(len == n) return dummy->next;
        head = dummy;
        while(head){
            cnt++;
            if(cnt + n == len){
                head->next = head->next->next;
                break;
            }
            head = head->next;
        }
        return dummy;
    }

    // one pass: O(N)time & space, 7.14%
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        unordered_map<int, ListNode*> nodes;
        ListNode* dummy = head;
        while(head){
            len++;
            nodes[len] = head;
            head = head->next;
        }
        // bug test case: [1,2], n=2, delete head
        if(len == n) return dummy->next;
        nodes[len - n]->next = nodes[len - n]->next->next;
        return dummy;
    }

    // Two pointers (one pass): O(N)time, O(1)space, 30.71%, ok
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);  // bug: don't forget to initialize
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        while(n--)  // fast pointer proceed n step first
            fast = fast->next;
        while(fast->next){  // when fast is the last elem, slow will be last n-1th
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
