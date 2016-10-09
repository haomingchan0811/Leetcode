class Solution {
public:
    // dynamic programming with O(n) space: 
    int uniquePaths(int m, int n){
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++)
                dp[j] += dp[j - 1];
        }
        return dp[n];
    }

    // // dynamic programming: 0ms
    // int uniquePaths(int m, int n) {
    //     int path[m][n];
    //     for(int i = 0; i < m; i++) path[i][0] = 1;
    //     for(int i = 0; i < n; i++) path[0][i] = 1;
    //     for(int i = 1; i < m; i++){
    //         for(int j = 1; j < n; j++)
    //             path[i][j] = path[i][j - 1] + path[i - 1][j];
    //     }
    //     return path[m - 1][n - 1];
    // }
};