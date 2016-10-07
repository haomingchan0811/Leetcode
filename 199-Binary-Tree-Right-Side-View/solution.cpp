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
    // 3ms
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(root == NULL) return ret;
        queue<TreeNode*> que;
        que.push(root);
        while(true){
            int queueSize = que.size();  // number of nodes for the current level of tree
            if(queueSize == 0) break;   
            int rightMost;              // the value of the right most tree node
            while(queueSize > 0){       // traverse a level of the tree
                TreeNode* temp = que.front();
                que.pop();
                rightMost = temp->val;
                if(temp->left != NULL) que.push(temp->left);
                if(temp->right != NULL) que.push(temp->right);
                queueSize --;
            }
            ret.push_back(rightMost);
        }
        return ret;
    }
};