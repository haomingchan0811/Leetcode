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
    // DFS with elegancy: 61.20%, ok
    int longestConsecutive(TreeNode* root) {
        return dfs(root, 0, nullptr);
    }

    int dfs(TreeNode* root, int depth, TreeNode* parent){
        if(!root) return depth;
        int childDepth;
        if(!parent) childDepth = 1;
        else childDepth = (root->val == parent->val + 1) ? depth + 1 : 1;
        return max(depth, max(dfs(root->left, childDepth, root), dfs(root->right, childDepth, root)));
    }

    // // DFS, 35.99%
    // int longestConsecutive(TreeNode* root) {
    //     if(!root) return 0;
    //     return dfs(root, 1);
    // }
    // // bug: 应该return max(现有的maxDepth, 子树的maxDepth)而不是max(左/右子树的maxDepth)
    // int dfs(TreeNode* root, int depth){
    //     if(!root->left && !root->right) return depth;
    //     int leftDepth, rightDepth;
    //     if(root->left && root->right){
    //         leftDepth = (root->left->val == root->val + 1) ? depth + 1 : 1;
    //         rightDepth = (root->right->val == root->val + 1) ? depth + 1 : 1;
    //         return max(max(leftDepth, rightDepth), max(dfs(root->left, leftDepth), dfs(root->right, rightDepth)));
    //     }
    //     if(root->left) {
    //         leftDepth = (root->left->val == root->val + 1) ? depth + 1 : 1;
    //         return max(leftDepth, dfs(root->left, leftDepth));
    //     }
    //     else{
    //         rightDepth = (root->right->val == root->val + 1) ? depth + 1 : 1;
    //         return max(rightDepth, dfs(root->right, rightDepth));
    //     }
    //     return 0;
    // }
};
