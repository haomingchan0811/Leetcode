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
    // hashmap: O(N), 4.33%,
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        unordered_map<ListNode*, int> flag;
        while(head){
            if(flag.find(head) == flag.end())
                flag[head] = 1;
            else return true;
            head = head->next;
        }
        return false;
    }

    // two pointers: O(N), 29.76%
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        // if there's a circle, the faster one will finally "catch" the slower one.
        while(fast && fast->next){    // bug: while(slow && fast)
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }

};
