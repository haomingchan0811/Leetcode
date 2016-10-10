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
    // int minDepth(TreeNode* root){
    //     if(!root) return 0;
    //     int minDepth =
    // }


    // BFS: 16ms
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        // int minDepth = INT_MAX;
        queue<TreeNode*> que;
        que.push(root);
        int level = 0;
        while(!que.empty()){
            int size = que.size();
            level++;
            while(size--){
                TreeNode* temp = que.front();
                que.pop();
                // if(!temp->left && !temp->right && minDepth > level) minDepth = level;
                if(!temp->left && !temp->right && minDepth > level) return level;
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
        }
        // return minDepth;
        return 0;
    }
};