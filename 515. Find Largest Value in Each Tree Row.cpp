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
    // BFS: O(N)time & space, 81.5%, ok
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int levelSize = q.size();
            int maxVal = INT_MIN;
            while(levelSize--){
                TreeNode* temp = q.front();
                q.pop();
                maxVal = max(maxVal, temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ret.push_back(maxVal);
        }
        return ret;
    }
};
