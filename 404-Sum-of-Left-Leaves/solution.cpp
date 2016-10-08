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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 0; // bug: solo root is not a left leaf
        queue<TreeNode*> que;   
        queue<bool> isLeft;         // isLeft reports whether this nomde is from a left child (potential to be a left leaf) 
        que.push(root);
        isLeft.push(false);
        int ans = 0;                // initial value
        while(!que.empty()){
            int size = que.size();  // current number of nodes of current level
            while(size--){
                TreeNode* temp = que.front();
                bool tempIsLeft = isLeft.front();
                que.pop();
                isLeft.pop();
                if(temp->left == NULL && temp->right == NULL && tempIsLeft) ans += temp->val;
                if(temp->left != NULL) {que.push(temp->left); isLeft.push(true);}
                if(temp->right != NULL) {que.push(temp->right); isLeft.push(false);}
            }
        }
        return ans;
    }
};