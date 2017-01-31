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
    // turn into a vector: O(N)time & space, 8.19%, ok
    ListNode* plusOne(ListNode* head) {
        if(!head) return NULL;
        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }
        int carry = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            carry += nums[i];
            nums[i] = carry % 10;
            carry /= 10;
        }
        ListNode* ret = new ListNode(0);
        ListNode* ans = ret;
        ret->val = carry? 1: nums[0];
        int i = carry? 0: 1;
        while(i < nums.size()){
            ListNode* temp = new ListNode(nums[i++]);
            ret->next = temp;
            ret = temp;
        }
        return ans;
    }

    // double reverse list: O(N)time & space, 8.19%, ok
    ListNode* plusOne(ListNode* head) {
        if(!head) return NULL;
        reverseList(head);
        int carry = 1;
        ListNode* newHead = head;
        ListNode* prev = NULL;
        while(head){
            prev = head;
            carry += head->val;
            head->val = carry % 10;
            carry /= 10;
            head = head->next;
        }
        if(carry) prev->next = new ListNode(1);
        reverseList(newHead);
        return newHead;
    }

    void reverseList(ListNode*& head){
        ListNode* prev = NULL;
        while(head && head->next){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        head->next = prev;
    }

   // two pointers: O(N)time, o(1)space, 8.19%, ok
   // find the righmost element (i) to increment
   ListNode* plusOne(ListNode* head) {
       if(!head) return NULL;
       ListNode* ret = new ListNode(0);
       ListNode* i = ret;
       i->next = head;
       while(head){
           if(head->val != 9)
               i = head;
           head = head->next;
       }
       i->val++;
       i=i->next;
       while(i){
           i->val = 0;
           i = i->next;
       }
       return ret->val? ret: ret->next;
   }
};
