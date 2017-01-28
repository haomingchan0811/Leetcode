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
    // recursive inorder traversal: 3ms
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        if(!root) return traversal;
        helper(root, traversal);
        return traversal;
    }

    void helper(TreeNode* root, vector<int> & traversal){
        if(!root) return;
        helper(root->left, traversal);
        traversal.push_back(root->val);
        helper(root->right, traversal);
    }

};
