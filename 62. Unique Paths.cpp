class Solution {
public:
    // dp[i][j]: #ways to move here, O(mn)time & space, 51.04%, ok
    int uniquePaths(int m, int n) {
        if(!m || !n) return 0;
        vector<vector<int>> ways(m, vector<int>(n, 1)); // base
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                ways[i][j] = ways[i - 1][j] + ways[i][j - 1];
        return ways[m - 1][n - 1];
    }

    // optimized dp: reuse vector line by line
    // O(mn)time, O(n)space, 51.04%, ok
    int uniquePaths(int m, int n) {
        if(!m || !n) return 0;
        vector<int> ways(n, 1); // base
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                ways[j] += ways[j - 1];
        return ways[n - 1];
    }
};
