class Solution {
public:
    // dynamic programming: ;using O(n) space
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<int> dp(col + 1, 0);
        dp[1] = 1;                      // initialize trick
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                dp[j] = obstacleGrid[i - 1][j - 1] == 0 ? dp[j] + dp[j - 1] : 0;
            }
        }
        return dp[col];
    }

    // // dynamic programming: 3ms; using O(mn) space
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int row = obstacleGrid.size();
    //     int col = obstacleGrid[0].size();
    //     int dp[row][col];
    //     if(obstacleGrid[0][0] == 1 || obstacleGrid[row - 1][col - 1] == 1) return 0; //bug: corner case
    //     dp[0][0] = 1;                       // starting point
    //     for(int i = 1; i < row; i++){       // initialize first column
    //         if(obstacleGrid[i][0] == 1){
    //             for(int j = i; j < row; j++) dp[j][0] = 0;
    //             break;
    //         }
    //         dp[i][0] = 1;
    //     }
    //     for(int i = 1; i < col; i++){       // initialize the first row
    //         if(obstacleGrid[0][i] == 1){
    //             for(int j = i; j < col; j++) dp[0][j] = 0;
    //             break;
    //         }
    //         dp[0][i] = 1;
    //     }
    //     for(int i = 1; i < row; i++){
    //         for(int j = 1; j < col; j++){
    //             if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
    //             else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    //         }
    //     }
    //     return dp[row - 1][col - 1];
    // }
};