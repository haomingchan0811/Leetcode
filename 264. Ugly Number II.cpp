class Solution {
public:
    // // dp: O(N)time & space, Time Limit Exceeded for large n
    // int nthUglyNumber(int n) {
    //     if(n < 1) return 0;
    //     // record whether i is an ugly number, corner case:dp[0] = dp[1] = 1;
    //     vector<int> dp(2, 1);
    //     int ret = 1;
    //     for(int i = 2; ret < n; i++){
    //         int isUgly;
    //         if((i % 2) && (i % 3) && (i % 5)) isUgly = 0;
    //         else{
    //             if(i % 5 == 0) isUgly = dp[i / 5];
    //             else if(i % 3 == 0) isUgly = dp[i / 3];
    //             else if(i % 2 == 0) isUgly = dp[i / 2];
    //         }
    //         dp.push_back(isUgly);
    //         ret += isUgly;
    //     }
    //     return dp.size() - 1;
    // }

    // dp: O(N)time & space, 32.15%, ok
    int nthUglyNumber(int n) {
        if(n < 1) return 0;
        vector<int> factors = {2, 3, 5};
        vector<int> ret(n + 1, INT_MAX);    // stores the ugly numbers
        // stores the index of the next ugly number that each factor has not multiply
        vector<int> nextIdx(3, 1);
        ret[1] = 1; // corner case
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < 3; j++)
                ret[i] = min(ret[i], factors[j] * ret[nextIdx[j]]);
            for(int j = 0; j < 3; j++)  // update to the next ugly number if chosen by ret[i]
                nextIdx[j] += (ret[i] == factors[j] * ret[nextIdx[j]]);  // when i=6, both 2 and 3 moves to the next num
        }
        return ret[n];
    }
};
