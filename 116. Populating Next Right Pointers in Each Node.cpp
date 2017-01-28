#include <iostream>
using namespace std;

//Definition for binary tree with next pointer.
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 
class Solution {
public:
    // 19ms
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> que;
        if(root == NULL) return;
        que.push(root);
        while(true){
            int size = que.size();
            if(size == 0) return;
            TreeLinkNode* prev = NULL;
            while(size > 0){
                TreeLinkNode* temp = que.front();
                que.pop();
                if(prev != NULL) prev->next = temp;
                prev = temp;
                if(temp->left != NULL) que.push(temp->left);
                if(temp->right != NULL) que.push(temp->right);
                size --;
            }
            prev->next = NULL;
        }
    }
};
