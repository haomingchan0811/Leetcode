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
    // BFS: O(N)time & space, 24.09%, ok
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int levelSize = q.size();
            if(levelSize) ret.push_back(q.front()->val);
            while(levelSize--){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
            }
        }
        return ret;
    }

    // DFS: O(N)time & space, 24.09%, ok
     vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        dfs(root, 0, ret);
        return ret;
    }

    void dfs(TreeNode* root, int level, vector<int>& ret){
        if(!root) return;
        if(ret.size() == level)     // brilliant idea
            ret.push_back(root->val);
        dfs(root->right, level + 1, ret); // key: travese rightmost node for every level first
        dfs(root->left, level + 1, ret);
    }
};
