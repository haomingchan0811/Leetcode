class Solution {
public:
     // count:O(N)time, O(1)space, 61.25%, ok
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.empty()) return 0;  // bug: corner case
        int cnt = (nums[0] == 1);
        int ret = cnt;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]) cnt++;
            else {
                ret = max(ret, cnt);
                cnt = 0;
            }
        }
        return max(ret, cnt);
    }
};
