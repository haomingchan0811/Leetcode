class Solution {
public:
    // extend from every 0: O(N)time, O(1)space, 1.69%
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = 0;
        if(nums.empty()) return ret;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0)
                ret = max(ret, extend(nums, i));
        }
        if(ret == 0) ret = nums.size();
        return ret;
    }

    int extend(vector<int> nums, int i){
        int length = 0;
        int left = i - 1, right = i + 1;
        bool stop = false;
        while(!stop){
            stop = true;
            if(left >= 0 && nums[left]){
                length++;
                left--;
                stop = false;
            }
            if(right < nums.size() && nums[right]){
                length++;
                right++;
                stop = false;
            }
        }
        return length + 1;
    }

    // online algo, compute on the fly: O(N)time, O(1)space, 22.83%, ok
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = 0, prev = 0, cnt = 0;
        if(nums.empty()) return ret;
        for(auto n: nums){
            if(n == 0){
                ret = max(ret, prev + cnt);
                prev = cnt + 1;
                cnt = 0;
            }
            else cnt++;
        }
        ret = max(ret, prev + cnt);
        if(ret == 0) ret = nums.size();
        return ret;
    }

};
