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
    // BFS and stack: 9ms
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> traversal;
        stack<vector<int>> level;
        if(root == NULL) return traversal;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> temp;
            while(size--){
                TreeNode* cur = que.front();
                que.pop();
                temp.push_back(cur->val);
                if(cur->left != NULL) que.push(cur->left);
                if(cur->right != NULL) que.push(cur->right);
            }
            level.push(temp);
        }
        while(!level.empty()){
            traversal.push_back(level.top());
            level.pop();
        }
        return traversal;
    }
};