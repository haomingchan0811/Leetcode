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
    // DFS: 40.54%, ok
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        dfs(root);
        return root;
    }

    void dfs(TreeNode* root){
        if(!root->left && !root->right) return;
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;
        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);
    }

    // DFS without auxilary function: 40.54%, ok
    TreeNode* invertTree(TreeNode* root){
        if(!root) return root;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
    
    // iterative/BFS: O(Nodes), 40.54%, ok
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            swap(temp->left, temp->right);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return root;
    }

};
