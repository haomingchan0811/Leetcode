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
    // recursive: 0ms, O(n)
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> traversal;
        if(!root) return traversal;
        helper(root, traversal);
        return traversal;
    }

    void helper(TreeNode* root, vector<int>& traversal){
        if(!root) return;
        helper(root->left, traversal);
        helper(root->right, traversal);
        traversal.push_back(root->val);
    }
};
