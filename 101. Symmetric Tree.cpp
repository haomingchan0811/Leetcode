/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // BFS: 3ms
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> p;
        queue<TreeNode*> q;
        p.push(root->left);
        q.push(root->right);
        while(!p.empty() || !q.empty()){
            TreeNode* l = p.front();
            TreeNode* r = q.front();
            p.pop();
            q.pop();
            if(!l && !r) continue;
            if(!l || !r) return false; // bug: if(!l || !r) return l == r;
            if(l->val != r->val) return false;
            p.push(l->left);
            p.push(l->right);
            q.push(r->right);
            q.push(r->left);
        }
        return true;
    }

    // DFS: 3ms
    bool isSymmetric(TreeNode* root){
        if(!root) return true;
        return DFS(root->left, root->right);
    }

    bool DFS(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        return DFS(p->left, q->right) && DFS(p->right, q->left);
    }
};
