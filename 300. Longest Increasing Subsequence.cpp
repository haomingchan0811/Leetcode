class Solution {
public:
    // dp[i]: length of LIS ending at i
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

    // binary search: O(NlogN)time, O(N)space, 75.86%, ok
    // keep an increasing list, replace the smallest elem that is larger than nums[i]
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ret = 1; // base
        vector<int> list(nums.size(), INT_MAX); // initialize to max
        list[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            // binary search: find smallest elem in the list which > nums[i]
            int head = 0, tail = i;
            while(head < tail){
                int mid = head + (tail - head) / 2;
                // bug: if(list[mid] <= nums[i])
                if(list[mid] < nums[i]) head = mid + 1;
                else if(list[mid] == nums[i]){
                    head = mid;
                    break;
                }
                else tail = mid;
            }
            list[head] = nums[i];
            ret = max(ret, head + 1);
        }
        return ret;
    }
};
