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
    // dfs: O(N)time & space, 40.72%, ok
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        if(!root) return ret;
        dfs(root, sum, vector<int>(), ret);
        return ret;
    }

    void dfs(TreeNode* root, int sum, vector<int> path, vector<vector<int>>& ret){
        path.push_back(root->val);
        if(!root->left && !root->right && sum == root->val)
            ret.push_back(path);
        if(root->left) dfs(root->left, sum - root->val, path, ret);  // brilliant idea of subtraction
        if(root->right) dfs(root->right, sum - root->val, path, ret);
    }
};
