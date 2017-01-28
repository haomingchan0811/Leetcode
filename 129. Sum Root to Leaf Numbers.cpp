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
    // DFS with string, O(Node), 9.12%, ok
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        vector<string> ans;
        dfs_string(root, ans, "");
        int ret = 0;
        for(int i = 0; i < ans.size(); i++) ret += stoi(ans[i]);
        return ret;
    }

    void dfs_string(TreeNode* root, vector<string>& ans, string sum){
        if(!root) return;
        if(!root->left && !root->right) ans.push_back(sum + to_string(root->val));
        if(root->left) dfs_string(root->left, ans, sum + to_string(root->val));
        if(root->right) dfs_string(root->right, ans, sum + to_string(root->val));
        return;
    }


    // DFS with calculation, O(Node), 9.12%, ok
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        vector<long> ans;
        dfs_num(root, ans, 0);
        int ret = 0;
        for(int i = 0; i < ans.size(); i++) ret += ans[i];
        return ret;
    }

    void dfs_num(TreeNode* root, vector<long>& ans, long sum){
        if(!root) return;
        if(!root->left && !root->right) ans.push_back(sum * 10 + root->val);
        if(root->left) dfs_num(root->left, ans, sum * 10 + root->val);
        if(root->right) dfs_num(root->right, ans, sum * 10 + root->val);
        return;
    }
};
