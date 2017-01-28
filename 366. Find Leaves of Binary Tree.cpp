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
    // recursive DFS: 2.06%
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ret;
        while(root){
            vector<int> leaf;
            dfs(root, leaf);
            ret.push_back(leaf);
        }
        return ret;
    }

    void dfs(TreeNode*& root, vector<int>& leaf){
        if(!root->left && !root->right){
            leaf.push_back(root->val);
            root = NULL;
            return;
        }
        if(root->left) dfs(root->left, leaf);
        if(root->right) dfs(root->right, leaf);
    }

    // DFS with depth: O(N) time & space, 2.06%, ok
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        dfs(root, ret);
        return ret;
    }

    int dfs(TreeNode* root, vector<vector<int>>& ret){
        if(!root) return -1;
        int level = max(dfs(root->left, ret), dfs(root->right, ret)) + 1;
        if(level >= ret.size()) ret.push_back(vector<int>());
        ret[level].push_back(root->val);
        return level;
    }
};
