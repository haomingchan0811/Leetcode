334. Increasing Triplet Subsequenceclass Solution {
public:
    // dp[i]: length of Longest Increasing Subarray ending at i
    // O(N2)time, O(N)space, TLE for last big data case;
    bool increasingTriplet(vector<int>& nums) {
        if(nums.empty()) return false;
        vector<int> len(nums.size(), 1);  // base case
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j])
                    len[i] = max(len[i], len[j] + 1);
            }
            if(len[i] == 3) return true;
        }
        return false;
    }

    // binary search: O(NlogN)time, O(N)space, 33.25%, ok
    // keep an increasing list, replace the smallest elem that is larger than nums[i]
    bool increasingTriplet(vector<int>& nums) {
        if(nums.empty()) return false;
        vector<int> list(nums.size(), INT_MAX);  // initialize to max
        for(int i = 0; i < nums.size(); i++){
            // binary search
            int head = 0, tail = i;
            while(head < tail){
                int mid = head + (tail - head) / 2;
                if(list[mid] > nums[i]) tail = mid;
                else if(list[mid] < nums[i]) head = mid + 1;
                else{ head = mid; break;}
            }
            list[head] = nums[i];
            if(head + 1 == 3) return true;
        }
        return false;
    }

};
