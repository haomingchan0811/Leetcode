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
    int maxDepth(TreeNode* root, int depth = 0) {
        if(root == NULL) return depth;
        else return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};