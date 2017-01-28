class Solution {
public:
    // brute force: 19.95%, ok
    bool isUgly(int num) {
        if(num < 1) return false;
        while(num % 10 == 0) num /= 10;  // not necessary, just to speed up
        while(num % 2 == 0) num /= 2;
        while(num % 3 == 0) num /= 3;
        while(num % 5 == 0) num /= 5;
        return num == 1;
    }

    // dp: O(N)time & space, Memory Limit Exceeded for large num
    bool isUgly(int num) {
        if(num < 1) return false;
        vector<int> dp(num + 1, 0);
        dp[0] = dp[1] = 1;  // corner case
        for(int i = 2; i <= num; i++){
            if((i % 2) && (i % 3) && (i % 5)) continue;
            else{
                if(i % 5 == 0) dp[i] = dp[i / 5];
                else if(i % 3 == 0) dp[i] = dp[i / 3];
                else if(i % 2 == 0) dp[i] = dp[i / 2];
            }
        }
        return dp[num];
    }
};
