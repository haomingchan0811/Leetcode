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
    // dfs: O(N)time & space, 53.98%, ok
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ret;
        unordered_map<int, int> cnt;
        int maxCnt = -1;
        int rootSum = dfs(root, cnt, maxCnt);
        for(auto pair: cnt){
            if(pair.second == maxCnt)
                ret.push_back(pair.first);
        }
        return ret;
    }

    int dfs(TreeNode* root, unordered_map<int, int>& cnt, int& maxCnt){
        if(!root) return 0;
        int currSum = root->val + dfs(root->left, cnt, maxCnt) + dfs(root->right, cnt, maxCnt);
        cnt[currSum]++;
        maxCnt = max(maxCnt, cnt[currSum]);
        return currSum;
    }


};
