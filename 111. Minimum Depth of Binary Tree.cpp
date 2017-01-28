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
    // DFS: 9ms
    int minDepth(TreeNode* root){
        if(!root) return 0;
        int level = 1;
        return DFS(root, INT_MAX, level);
    }

    int DFS(TreeNode* root, int minDepth, int level){
        if(!root) return INT_MAX;
        if(!root->left && !root->right) return level;
        return min(DFS(root->left, minDepth, level + 1), DFS(root->right, minDepth, level + 1));
    }

    // BFS: 16ms -> 9ms(replace the anotated lines with their below lines, stop when found the first leaf)
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
                if(!temp->left && !temp->right) return level;
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
        }
        // return minDepth;
        return 0;
    }
};
