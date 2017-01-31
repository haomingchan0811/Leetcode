/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct cmp{
    bool operator() (pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
};

class Solution {
public:
    // traverse and add pair into priority queue: O(N)time & space, slow
    vector<int> findMode(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        unordered_map<int, int> map;
        dfs(root, map);
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for(auto pair: map) pq.push(pair);
        int cnt = pq.top().second;
        ret.push_back(pq.top().first);
        pq.pop();
        while(pq.size() && pq.top().second == cnt){
            ret.push_back(pq.top().first);
            pq.pop();
        }
        return ret;
    }

    void dfs(TreeNode* root, unordered_map<int, int>& map){
        map[root->val]++;
        if(root->left) dfs(root->left, map);
        if(root->right) dfs(root->right, map);
    }
};
