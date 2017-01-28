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
    // O(n), 13.34%
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        int a = l1->val, b = l2->val;
        // bug: type modifier（*/&）只对其后面跟的第一个对象有效：int* p1, p2; // p1是int指针，p2是int
        ListNode* ans;
        ListNode* p;
        ans = p = new ListNode((a + b) % 10);
        int carry = (a + b) / 10;
        while(l1->next || l2->next || carry){
            cout << a << " " << b << endl;
            if(l1->next){
                l1 = l1->next;
                a = l1->val;
            }
            else a = 0;
            if(l2->next){
                l2 = l2->next;
                b = l2->val;
            }
            else b = 0;
            ans->next = new ListNode ((a + b + carry) % 10);
            ans = ans->next;
            carry = (a + b + carry) / 10;
        }
        return p;
    }
};
