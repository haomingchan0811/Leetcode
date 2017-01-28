class Solution {
public:
    // DP: direction[i][j] -> how many enemt can be killed at this position from a specific direction
    // O(NM) time & space, 36.13%, ok (can reuse a same matrix for 4 directions, however, 4 matrixes are more understandable)
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int row = grid.size(), col = grid[0].size();
        int maxKill = 0;

        // from upperleft to lowerright
        vector<vector<int>> left(row, vector<int>(col, 0));
        vector<vector<int>> up(row, vector<int>(col, 0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] != 'W'){
                    up[i][j] = (i > 0 ? up[i - 1][j] : 0) + (grid[i][j] == 'E');
                    left[i][j] = (j > 0 ? left[i][j - 1] : 0) + (grid[i][j] == 'E');
                }
            }
        }

        // from lowerright to upperleft
        vector<vector<int>> right(row, vector<int>(col, 0));
        vector<vector<int>> down(row, vector<int>(col, 0));
        for(int i = row - 1; i >= 0; i--){
            for(int j = col - 1; j >= 0; j--){
                if(grid[i][j] != 'W'){
                    down[i][j] = (i < row - 1 ? down[i + 1][j] : 0) + (grid[i][j] == 'E');
                    right[i][j] = (j < col - 1 ? right[i][j + 1] : 0) + (grid[i][j] == 'E');
                    if(grid[i][j] != 'E')
                        maxKill = max(maxKill, up[i][j] + down[i][j] + left[i][j] + right[i][j]);
                }
            }
        }
        // printf("%d-%d-%d-%d", up[1][1], down[1][1], left[1][1], right[1][1]);
        return maxKill;
    }
};
