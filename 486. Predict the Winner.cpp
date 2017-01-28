class Solution {
public:
    // recursive simulation: O(2^N)time, O(1)space, 2.00%
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.empty()) return true;
        return helper(nums, 0, nums.size() - 1, 0, 0);
    }

    bool helper(vector<int> nums, int head, int tail, int score1, int score2){
        if(head == tail)
            return score1 + nums[head] >= score2;
        if(head > tail) return score1 >= score2;
        bool fetchHead1 = helper(nums, head + 2, tail, score1 + nums[head], score2 + nums[head + 1]);
        bool fetchHead2 = helper(nums, head + 1, tail - 1, score1 + nums[head], score2 + nums[tail]);
        if(fetchHead1 && fetchHead2) return true;
        bool fetchTail1 = helper(nums, head + 1, tail - 1, score1 + nums[tail], score2 + nums[head]);
        bool fetchTail2 = helper(nums, head, tail - 2, score1 + nums[tail], score2 + nums[tail - 1]);
        return fetchTail1 && fetchTail2;
    }

    // dp: O(N2)time, O(1)space, 37.07%, ok
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.empty()) return true;
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        vector<vector<int>> sum(size, vector<int>(size, 0));
        // initialize base case and sum
        for(int i = 0; i < size; i++){
            dp[i][i] = sum[i][i] = nums[i];
            for(int j = i + 1; j < nums.size(); j++)
                sum[i][j] = sum[i][j - 1] + nums[j];
        }
        for(int i = 1; i < size; i++){
            for(int j = 0; j < size - i; j++){
                // key: expand bi-directionally from dp[i][i] by 1 step each time
                int selectHead = nums[j] + sum[j + 1][j + i] - dp[j + 1][j + i];
                int selectTail = nums[j + i] + sum[j][j + i - 1] - dp[j][j + i - 1];
                dp[j][j + i] = max(selectHead, selectTail);
            }
        }
        return dp[0][size - 1] >= sum[0][size - 1] * 1.0 / 2;
    }
};
