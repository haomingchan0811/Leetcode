#include <iostream>
#include <queue>
using namespace std;

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
    // DFS with elegancy: O(Node), 16.40%, 6ms
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        else return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    // BFS: 16ms
    int maxDepth(TreeNode* root){
        if(root == NULL) return 0;
        queue<TreeNode *> que;
        que.push(root);
        int depth = 0;
        while(!que.empty()){
            depth ++;       // every layer of tree nodes
            // bug: i<que.size(), size of queue change from time to time, should settle down the value before each for iteration.
            int size = que.size();
            for(int i = 0; i < size; i ++){
                TreeNode *temp = que.front();
                que.pop();
                if(temp->left != NULL) que.push(temp->left);
                if(temp->right != NULL) que.push(temp->right);
            }
        }
        return depth;
    }
};
