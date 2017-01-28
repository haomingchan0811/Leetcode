class Solution {
public:
    // sort, memorized DP: O(N2)time and space, 43.13%, ok
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.empty()) return nums;
        sort(nums.begin(), nums.end());
        // divisible set with the i-th element as the largest
        vector<vector<int>> dp(nums.size(), vector<int>());
        int maxGlobal = 0;
        for(int i = 0; i < nums.size(); i++){
            int maxIdx = -1;
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && (maxIdx == -1 || dp[maxIdx].size() < dp[j].size()))
                    maxIdx = j;
            }
            if(maxIdx != -1)
                dp[i].insert(dp[i].begin(), dp[maxIdx].begin(), dp[maxIdx].end());
            dp[i].push_back(nums[i]);
            maxGlobal = dp[i].size() > dp[maxGlobal].size()? i : maxGlobal;
        }
        return dp[maxGlobal];
    }

    // sort, memorized DP: O(N2)time O(N)space, 75.59%, ok
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.empty()) return nums;
        sort(nums.begin(), nums.end());
        // size of divisible set with the i-th element as the largest
        vector<int> dp(nums.size(), 1);
        vector<int> parent(nums.size(), 0);  // trace back one's parent
        int maxGlobal = 0;
        for(int i = 0; i < nums.size(); i++){
            int maxIdx = -1;
            parent[i] = i;
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && (maxIdx == -1 || dp[maxIdx] < dp[j]))
                    maxIdx = j;
            }
            if(maxIdx != -1) {
                dp[i] = dp[maxIdx] + 1;
                parent[i] = maxIdx;
            }
            maxGlobal = dp[i] > dp[maxGlobal]? i : maxGlobal;
        }
        vector<int> ret;
        while(parent[maxGlobal] != maxGlobal){
            ret.push_back(nums[maxGlobal]);
            maxGlobal = parent[maxGlobal];
        }
        ret.push_back(nums[maxGlobal]);
        return ret;
    }
};
