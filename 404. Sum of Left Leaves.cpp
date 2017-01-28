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
    // DFS: O(N)time, O(1)space, 2.85%, ok
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        dfs(root, sum, false);
        return sum;
    }

    void dfs(TreeNode* root, int& sum, bool isLeft){
        if(!root) return;
        if(!root->left && !root->right && isLeft)
            sum += root->val;
        dfs(root->left, sum, true);
        dfs(root->right, sum, false);
    }

    // DFS without marker: O(N)time, no space, 2.85%, ok
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root);
    }

    int dfs(TreeNode* root){
        if(!root) return 0;
        if(root->left && !root->left->left && !root->left->right)
            return root->left->val + dfs(root->right);
        else return dfs(root->left) + dfs(root->right);
    }
};
