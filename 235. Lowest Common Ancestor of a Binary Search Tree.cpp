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
    // classified discussion: O(logN), 13.4%
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q) return NULL;
        if((root->val - p->val) * (root->val - q->val) <= 0) return root;
        root = root->val > p->val? root->left : root->right;
        return lowestCommonAncestor(root, p, q);
    }
};
