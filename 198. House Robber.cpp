class Solution {
public:
    // DP: ans[i] stores the maximum amount of money robbed so far for the i-th house.
    // O(N2) time, O(N) space: 26.51%, ok
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(!size) return 0;
        vector<int> ans(size, 0);
        ans[0] = nums[0];
        for(int i = 1; i < size; i++){
            int maxRob = 0;
            for(int j = 0; j < i - 1; j++)
                maxRob = max(maxRob, ans[j]);
            ans[i] = max(ans[i - 1], nums[i] + maxRob);
        }
        return ans[size - 1];
    }

    // further improvement: O(1) to find the unadjacent maxRob
    // O(N) time, O(1) space: 26.51%, ok
     int rob(vector<int>& nums) {
        int size = nums.size();
        if(!size) return 0;
        int ans = nums[0];
        int prev = 0;   // store the maximum of ans[0 ~ i-2]
        for(int i = 1; i < size; i++){
            int temp = ans;
            ans = max(ans, nums[i] + prev);
            prev = temp;
        }
        return ans;
    }
};
