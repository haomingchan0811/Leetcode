class Solution {
public:
    // DFS: O(N2)time & space, 42.76%, ok
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int ret = 0, i = 0;
        if(edges.empty()) return n;  // bug: individual points are connected components too
        vector<int> visited(n, 0);
        unordered_map<int, vector<int>> adj;
        for(int j = 0; j < n; j++) adj[j] = vector<int>();
        for(auto p: edges){
            adj[p.first].push_back(p.second);
            adj[p.second].push_back(p.first);
        }
        while(i < n) {
            if(visited[i]) {i++; continue;}
            dfs(i, adj, ret, visited);
            i++; ret++;
        }
        return ret;
    }

    void dfs(int i, unordered_map<int, vector<int>>& adj, int& ret, vector<int>& visited){
        if(visited[i]) return;
        visited[i] = 1;
        for(auto node: adj[i]) dfs(node, adj, ret, visited);
    }

    // union find: O(mlogN)time (m = vectorSize), O(N)space, 42.7%, ok
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int ret = n;
        vector<int> root;
        for(int i = 0; i < n; i++) root.push_back(i);
        for(auto e: edges){
            int root1, root2;
            int i = e.first, j = e.second;
            while(i != root[i]) i = root[i];
            while(j != root[j]) j = root[j];
            if(i != j){
                root[i] = j;
                ret--;
            }
        }
        return ret;
    }
};
