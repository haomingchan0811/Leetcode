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

    // // BFS: O(N)time & space, TLE for large data
    // bool isSymmetric(TreeNode* root) {
    //     if(!root) return true;
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     bool isRoot = true;
    //     while(q.size()){
    //         int size = q.size(), halfsize = q.size() / 2;
    //         stack<int> s;
    //         bool allNull = true;
    //         while(size--){
    //             TreeNode* temp = q.front();
    //             q.pop();
    //             if(temp) allNull = false;
    //             int curr = temp? temp->val: NULL;
    //             if(size >= halfsize) s.push(curr);
    //             else{
    //                 if(curr != s.top()) return false;
    //                 s.pop();
    //             } 
    //             TreeNode* leftNode = temp? temp->left: NULL;
    //             TreeNode* rightNode = temp? temp->right: NULL;
    //             q.push(leftNode);
    //             q.push(rightNode);
    //         }
    //         if(!s.empty() && !isRoot) return false;
    //         isRoot = false;
    //         if(allNull) break;
    //     }
    //     return true;
    // }
    
    // recursive:  O(N)time & space, 36.07%, ok
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        return (p->val == q->val) && helper(p->left, q->right) && helper(p->right, q->left);
    }
};
