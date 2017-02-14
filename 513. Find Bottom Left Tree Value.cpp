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
    // BFS: O(N)time & space, 26.82%, ok
    int findBottomLeftValue(TreeNode* root) {
        int ret;
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int levelSize = q.size();
            ret = q.front()->val;
            while(levelSize--){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return ret;
    }

    // DFS: O(N)time & space, 51.59%, ok
    int findBottomLeftValue(TreeNode* root) {
        int ret = INT_MIN;
        int currDepth = -1;
        if(!root) return 0;
        dfs(root, ret, currDepth, 0);
        return ret;
    }

    void dfs(TreeNode* root, int& ret, int& currDepth, int depth){
        if(depth > currDepth){   // bug: tricky condition!
            ret = root->val;    // the leftmost node is always traversed first in the same level
            currDepth = depth;
        }
        if(root->left) dfs(root->left, ret, currDepth, depth + 1);
        if(root->right) dfs(root->right, ret, currDepth, depth + 1);
    }
};
