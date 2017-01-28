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
    // dfs: O(N2)time, O(N)space, 14.43%
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        int ret = 0;
        dfs(root, ret, sum, vector<int>());
        return ret;
    }

    void dfs(TreeNode* root, int& ret, int sum, vector<int> sub){
        for(int i = 0; i < sub.size(); i++){
            sub[i] += root->val;
            if(sub[i] == sum) ret++;
        }
        sub.push_back(root->val);
        if(sum == root->val) ret++;
        if(root->left)
            dfs(root->left, ret, sum, sub);
        if(root->right)
            dfs(root->right, ret, sum, sub);
    }

    // two pass dfs: O(N2)time, O(N)space, 81.62%, ok
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int dfs(TreeNode* root, int sum){
        if(!root) return 0;
        return (root->val == sum) + dfs(root->left, sum - root->val) + dfs(root->right, sum - root->val);
    }
};
