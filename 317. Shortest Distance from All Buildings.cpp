class Solution {
private:
    int m, n;
    vector<int> dir = {0, 1, 0, -1, 0};
public:
    // BFS: O(mnk)time & space (k: #buildings), 42.33%, ok
    int shortestDistance(vector<vector<int>>& grid) {
        if(grid.empty()) return -1;
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0));
        int ret = INT_MAX;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1)
                    bfs(grid, dist, i, j, ret);
            }
        }
        // TLE -> optimize: update ret in the bfs to reduce runtime
        return ret == INT_MAX? -1: ret;
    }

    void bfs(vector<vector<int>>& grid, vector<vector<int>>& dist, int a, int b, int& ret){
        // TLE -> optimize: combine visited and distance together to reduce runtime
        vector<vector<int>> visitedAndDist(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        q.push(make_pair(a, b));
        int minDist = INT_MAX;
        while(q.size()){
            int i = q.front().first, j = q.front().second;
            q.pop();
            for(int k = 0; k < 4; k++){
                int x = i + dir[k], y = j + dir[k + 1];
                if(x < 0 || x > m - 1 || y < 0 || y > n - 1 || visitedAndDist[x][y]
                   || grid[x][y] == 1 || grid[x][y] == 2  || dist[x][y] == INT_MAX)
                    continue;
                visitedAndDist[x][y] = visitedAndDist[i][j] + 1;
                q.push(make_pair(x, y));
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visitedAndDist[i][j] == INT_MAX || grid[i][j] == 1 || grid[i][j] == 2) continue;
                if(!visitedAndDist[i][j]) dist[i][j] = INT_MAX;
                else dist[i][j] += visitedAndDist[i][j];
                minDist = min(minDist, dist[i][j]);
            }
        }
        ret = minDist;
    }
};
