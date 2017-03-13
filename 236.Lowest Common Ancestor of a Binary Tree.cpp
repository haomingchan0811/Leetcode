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
    // // brute force: O(N)time& space, TLE for large data
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     vector<TreeNode*> path_p = findPath(root, p, vector<TreeNode*>());
    //     vector<TreeNode*> path_q = findPath(root, q, vector<TreeNode*>());
    //     int i = 0, j = 0;
    //     while(i < path_p.size() && j < path_q.size()){
    //         if(path_p[i] == path_q[j]){
    //             i++; j++;
    //         }
    //         else return path_p[i - 1];
    //     }
    //     return i == path_p.size()? path_p[i - 1]: path_q[j - 1];
    // }

    // vector<TreeNode*> findPath(TreeNode* root, TreeNode* t, vector<TreeNode*> path){
    //     if(!root) return vector<TreeNode*>();
    //     path.push_back(root);
    //     if(root == t) return path;
    //     vector<TreeNode*> left = findPath(root->left, t, path);
    //     vector<TreeNode*> right = findPath(root->right, t, path);
    //     return left.empty()? right: left;
    // }

    // recursive: O(N)time, O(1)space, 53.10%, ok
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right) return root;
        return !left? right: left;
    }
};
