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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> path;
        if(!root) return path;
        DFS(path, root, to_string(root->val));
        return path;
    }

    void DFS(vector<string>& path, TreeNode* root, string curr){
        if(!root) return;
        if(!root->left && !root->right){
            path.push_back(curr);
            return;
        }
        if(root->left) DFS(path, root->left, curr + "->" + to_string(root->left->val));
        if(root->right) DFS(path, root->right, curr + "->" + to_string(root->right->val));
    }

    // dfs: O(N), 17.33%, ok
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if(!root) return ret;
        dfs(root, "", ret);
        return ret;
    }

    void dfs(TreeNode* root, string path, vector<string>& ret){
        if(!root->left && !root->right){
            path += "->" + to_string(root->val);
            ret.push_back(path.substr(2));
        }
        if(root->left) dfs(root->left, path + "->" + to_string(root->val), ret);
        if(root->right) dfs(root->right, path + "->" + to_string(root->val), ret);
    }
};
