/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    // BFS: O(N)time & space, 40.61%, ok
    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(q.size()){
            int size = q.size();
            TreeLinkNode* prev = NULL;
            while(size--){
                TreeLinkNode* temp = q.front();
                q.pop();
                if(prev) prev->next = temp;
                prev = temp;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
    }

    // DFS on the left child: O(N)time, O(1)space, 40.61%, ok
    void connect(TreeLinkNode *root) {
        if(!root) return;
        while(root->left){
            TreeLinkNode* p = root;
            while(p){
                p->left->next = p->right;
                if(p->next) p->right->next = p->next->left;
                p = p->next;
            }
            root = root->left;
        }
    }
};
