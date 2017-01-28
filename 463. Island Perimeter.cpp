class Solution {
private:
    int m, n;
public:
    // DFS: O(MN), 75.49%, ok
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int ret = 0;
        m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    dfs(i, j, grid, ret);
                    return ret;
                }
            }
        }
        return 0;
    }

    void dfs(int i, int j, vector<vector<int>>& grid, int& ret){
        // bug: "grid[i][j] != 1"放在了判断语句的最前面，可能会越界
        if((i < 0) || (j < 0) || (i == m) || (j == n) || (grid[i][j] != 1)) return;
        // bug: "grid[i][j] = 0", wrong as it changed the water neighborhood for the remaining grid
        grid[i][j] = -1;    // mark traversed grid
        if((i == 0) || (grid[i - 1][j] == 0)) ret++;
        if((j == 0) || (grid[i][j - 1] == 0)) ret++;
        if((i == m - 1) || (grid[i + 1][j] == 0)) ret++;
        if((j == n - 1) || (grid[i][j + 1] == 0)) ret++;
        dfs(i + 1, j, grid, ret);
        dfs(i - 1, j, grid, ret);
        dfs(i, j + 1, grid, ret);
        dfs(i, j - 1, grid, ret);
        return;
    }

    // check inner shared boundries: O(MN), 90.55%, ok
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int cnt = 0, shared = 0;
        m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    cnt++;
                    if(i && grid[i - 1][j]) shared++;
                    if(j && grid[i][j - 1]) shared++;
                }
            }
        }
        return cnt * 4 - 2 * shared;
    }

};
