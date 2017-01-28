class Solution {
private:
    int row;
    int col;
public:
    // // DFS: O(MN)time & space, 22.03%, ok
    // int numIslands(vector<vector<char>>& grid) {
    //     if(!grid.size() || !grid[0].size()) return 0;
    //     row = grid.size(), col = grid[0].size();
    //     int ret = 0;
    //     vector<vector<bool>> visited(row, vector<bool>(col, 0));
    //     for(int i = 0; i < row; i++){
    //         for(int j = 0; j < col; j++){
    //             if(!visited[i][j] && grid[i][j] == '1'){
    //                 ret++;
    //                 dfs(grid, visited, i, j);
    //             }
    //             else visited[i][j] = 1;
    //         }
    //     }
    //     return ret;
    // }

    // void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
    //     if(i < 0 || i >= row || j < 0 || j >= col || visited[i][j] ) return;
    //     visited[i][j] = 1;
    //     if(grid[i][j] == '1'){
    //         dfs(grid, visited, i - 1, j);
    //         dfs(grid, visited, i + 1, j);
    //         dfs(grid, visited, i, j - 1);
    //         dfs(grid, visited, i, j + 1);
    //     }
    // }

    // DFS: reuse the original matrix for flagging: O(MN)time, O(1)space, 74.16%, ok
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size() || !grid[0].size()) return 0;
        row = grid.size(), col = grid[0].size();
        int ret = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    ret++;
                    dfs(grid, i, j);
                }
            }
        }
        return ret;
    }

    void dfs(vector<vector<char>>& grid, int i, int j){
        if(grid[i][j] == '0') return;
        grid[i][j] = '0';
        if(i > 0) dfs(grid, i - 1, j);
        if(j > 0) dfs(grid, i, j - 1);
        if(i < row - 1) dfs(grid, i + 1, j);
        if(j < col - 1) dfs(grid, i, j + 1);
    }

    // Union Find: to be continued

};
