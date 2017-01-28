class Solution {
public:
    // dp: O(Nmn)time, O(mn)space, 62.95%, ok
    int findMaxForm(vector<string>& strs, int m, int n) {
        if(strs.empty()) return 0;
        // dp[i][j] is the maximal number of strings represented with i zeroes and j ones
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(auto s: strs){
            int zeroes = 0, ones = 0;
            for(auto c: s){
                if(c == '0') zeroes++;
                else ones++;
            }
            // from bottom-right to top-left to avoid recounting
            for(int i = m; i >= zeroes; i--){
                for(int j = n; j >= ones; j--){
                    dp[i][j] = max(dp[i][j], dp[i - zeroes][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
