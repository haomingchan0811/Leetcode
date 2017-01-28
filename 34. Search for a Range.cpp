class Solution {
public:
    // STL: O(logN)time, O(1)space, 26.07%, ok
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(begin == nums.size() || nums[begin] != target) // bug: miss "begin ?= nums.size()"
            return vector<int> (2, -1);
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        vector<int> ret = {begin, end};
        return ret;
    }

    // bianry search: O(logN)time, O(1)space, 41.27%, ok
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = INT_MAX, end = INT_MIN;
    // search for the left range (lower bound)
        int head = 0, tail = nums.size() - 1;
        while(head <= tail){
            int mid = head + (tail - head) / 2;
            if(nums[mid] == target){
                begin = min(begin, mid);
                tail--;
            }
            else if(nums[mid] > target)
                tail = mid - 1;
            else head = mid + 1;
        }
        if(begin == INT_MAX)
            return vector<int> (2, -1);
    // search for the right range (upper bound)
        head = 0, tail = nums.size() - 1;
        while(head <= tail){
            int mid = head + (tail - head) / 2;
            if(nums[mid] == target){
                end = max(begin, mid);
                head++;
            }
            else if(nums[mid] > target)
                tail = mid - 1;
            else head = mid + 1;
        }
        vector<int> ret = {begin, end};
        return ret;
    }

    // more elegant bianry search: O(logN)time, O(1)space, 41.27%, ok
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        if(nums.empty()) return ret;
        // search for the left range (lower bound)
        int head = 0, tail = nums.size() - 1;
        while(head < tail){  // notice: not "<="
            int mid = head + (tail - head) / 2;
            if(nums[mid] < target)
                head = mid + 1;
            else tail = mid;
        }
        if(nums[head] != target) return ret;
        else ret[0] = head;

        // search for the right range (upper bound)
        head = 0, tail = nums.size() - 1;
        while(head < tail){
            int mid = head + (tail - head) / 2 + 1;  // trick: bias to right by 1 to avoid stuck
            if(nums[mid] > target)
                tail = mid - 1;
            else head = mid;
        }
        ret[1] = head;
        return ret;
    }
};
