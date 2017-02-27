class Solution {
public:
    // dp[i]: length of LIS ending at j
    // O(N2)time, O(N)space, 57.19%, ok
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ret = 1;
        vector<int> len(nums.size(), 1); // base case
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j])
                    len[i] = max(len[i], len[j] + 1);
            }
            ret = max(ret, len[i]);
        }
        return ret;
    }
};
