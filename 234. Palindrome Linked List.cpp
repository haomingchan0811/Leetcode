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
    // copy and two pointers: O(N)time & space, 57.81%, ok
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        int i = 0, j = v.size() - 1;
        while(i < j){
            if(v[i++] != v[j--])
                return false;
        }
        return true;
    }

    // reverse the 2nd half and compare: O(N)time O(1)space, 57.81%, ok
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        //循环结束时，slow正好在数组中间
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        // odd number of nodes, 可以忽略这一步，只是多一次无意义的比较
        if(fast) slow = slow->next;

        slow = reverse(slow);
        while(slow && head){
            if(slow->val != head->val)
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }

    ListNode* reverse(ListNode* head){
        ListNode* pre = NULL;
        while(head){
            ListNode* Next = head->next;
            head->next = pre;
            pre = head;
            head = Next;
        }
        return pre;
    }
};
