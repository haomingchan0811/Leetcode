class Solution {
public:
    // // recursive: TLE
    // int numSquares(int n) {
    //     if(!n) return 0;
    //     if(n == 1) return 1;
    //     int ret = INT_MAX;
    //     for(int i = sqrt(n); i >= 1; i--){
    //         int num = i * i;
    //         if(n == num) return 1;
    //         ret = min(ret, numSquares(n - num) + 1);
    //     }
    //     return ret;
    // }

    // dp: O(n^1.5) time, O(n)space, 38.48%, ok
    int numSquares(int n) {
        if(!n) return 0;
        vector<int> dp(n + 1, INT_MAX);
        for(int i = 1; i <= n; i++){
            int root = sqrt(i);
            if(root * root == i) dp[i] = 1;
            else{
                for(int j = root; j >= 1; j--){
                    int square = j * j;
                    dp[i] = min(dp[i], dp[i - square] + 1);
                }
            }
        }
        return dp[n];
    }
};
