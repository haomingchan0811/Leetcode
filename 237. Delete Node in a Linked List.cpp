#include <iostream>
using namespace std;

//efinition for singly-linked list.
truct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 75.87%, ok
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        auto temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};
