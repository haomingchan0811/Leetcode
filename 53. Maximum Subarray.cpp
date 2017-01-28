class Solution {
public:
    // brute force: O(N2), TLE for big data case
    // int maxSubArray(vector<int>& nums) {
    //     int sum = INT_MIN;
    //     if(nums.empty()) return 0;
    //     for(int i = 0; i < nums.size(); i++){
    //         int temp = nums[i];
    //         int maxTemp = nums[i];
    //         for(int j = i + 1; j < nums.size(); j++){
    //             temp += nums[j];
    //             maxTemp = max(maxTemp, temp);
    //         }
    //         sum = max(maxTemp, sum);
    //     }
    //     return sum;
    // }

    // DP(bottom2top): O(N) time and space, 32.56%, ok
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size(), 0); // dp[i] records the maximal subarray that starts with dp[i]
        int ret = dp[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = nums.size() - 2; i >= 0; i--){
            dp[i] = max(nums[i], nums[i] + dp[i+1]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }

    // DP(top2bottom): O(N) time and space, 32.56%, ok
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size(), 0); // dp[i] records the maximal subarray that ends with dp[i]
        int ret = dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(nums[i], nums[i] + dp[i-1]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
