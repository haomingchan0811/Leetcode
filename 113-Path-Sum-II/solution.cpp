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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> target;
        if(!root) return target;
        vector<int> path(1, root->val);
        DFS(target, sum, root, root->val, path);
        return target;
    }
    
    void DFS(vector<vector<int>>& target, int sum, TreeNode* root, int curSum, vector<int> cur){
        if(!root) return;
        if(!root->left && !root->right)
            if(curSum == sum) target.push_back(cur);
        // bug: if(curSum </!= sum) -> Consider negative values and combo calculation that has intermediate sum equals to target sum
        if(root->left){
            vector<int> temp = cur;
            temp.push_back(root->left->val);
            DFS(target, sum, root->left, curSum + root->left->val, temp);
        }            
        if(root->right){
            vector<int> temp = cur;
            temp.push_back(root->right->val);
            DFS(target, sum, root->right, curSum + root->right->val, temp);
        } 
        return;
    }
};