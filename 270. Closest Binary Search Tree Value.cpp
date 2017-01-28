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
    // recursive: O(logN), 63.49%, ok
    int closestValue(TreeNode* root, double target) {
        TreeNode* child = root->val > target? root->left: root->right;
        if(!child) return root->val;
        int childVal = closestValue(child, target);
        return abs(target - root->val) < abs(target - childVal)? root->val : childVal;
    }

    // iterative binary search: O(logN), 50.20%, ok
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        while(root){
            if(abs(target - closest) > abs(target - root->val))
                closest = root->val;
            root = root->val > target? root->left: root->right;
        }
        return closest;
    }
};
