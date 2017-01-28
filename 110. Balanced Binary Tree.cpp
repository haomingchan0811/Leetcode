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
    // DFS:
    bool isBalanced(TreeNode* root) {
        if(DFS(root) == -1) return false;
        else return true;
    }

    int DFS(TreeNode* root){
        if(!root) return 0;
        int left = DFS(root->left);
        int right = DFS(root->right);
        if(left == -1 || right == -1) return -1;
        return abs(left - right) <= 1 ? max(left, right) + 1: -1;
    }
};
