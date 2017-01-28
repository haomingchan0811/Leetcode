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
    // BFS & reverse: O(N)time & space, 31.08%, ok
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(q.size()){
            level++;
            int levelSize = q.size();
            vector<int> temp;
            while(levelSize--){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(!(level & 1)) reverse(temp.begin(), temp.end());
            ret.push_back(temp);
        }
        return ret;
    }

    // BFS without reverse: O(N)time & space, 31.08%, ok
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        int index, level = 0;
        while(q.size()){
            level++;
            int levelSize = q.size();
            vector<int> temp(levelSize, 0);
            for(int i = 0; i < levelSize; i++){
                TreeNode* node = q.front();
                q.pop();
                index = (level & 1)? i : levelSize - i - 1;
                temp[index] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ret.push_back(temp);
        }
        return ret;
    }
};
