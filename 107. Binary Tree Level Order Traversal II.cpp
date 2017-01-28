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
    // stack: O(N)time, O(depth)space, 33.26%, ok
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        stack<vector<int>> filo;
        while(q.size()){
            int size = q.size();
            vector<int> level;
            while(size--){
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            filo.push(level);
        }
        while(filo.size()){
            ret.push_back(filo.top());
            filo.pop();
        }
        return ret;
    }

    // STL: O(N)time, O(1)space, 33.26%, ok
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int size = q.size();
            vector<int> level;
            while(size--){
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ret.push_back(level);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
