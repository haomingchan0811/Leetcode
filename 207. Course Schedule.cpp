class Solution {
public:
    // DFS: build graph and find circle, O(N2)time, O(N)space, 58.97%, ok
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> adj(numCourses, unordered_set<int>());
        for(auto p: prerequisites)
            adj[p.second].insert(p.first);
        vector<int> visited(numCourses, 0);
        vector<int> currCheck(numCourses, 0);
        for(int node = 0; node < numCourses; node++){
            if(!visited[node] && findCycle(node, visited, currCheck, adj))
                return false;
        }
        return true;
    }
    
    bool findCycle(int node, vector<int>& visited, vector<int>& currCheck, vector<unordered_set<int>>& adj){
        if(visited[node]) return false;
        visited[node] = currCheck[node] = 1;
        for(auto neighbor: adj[node]){
            if(currCheck[neighbor] || findCycle(neighbor, visited, currCheck, adj))
                return true;
        }
        currCheck[node] = 0;
        return false;
    }
};