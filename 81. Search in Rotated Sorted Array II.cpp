class Solution {
public:
    // binary search with duplicates: O(logN)time (worst O(N)), O(1)space, 35.84%, ok
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        int head = 0, tail = nums.size() - 1;
        while(head <= tail){
            int mid = head + (tail - head) / 2;
            if(nums[mid] == target) return true;
            if(nums[mid] > nums[head]){   // monotone
                if(nums[head] <= target && target < nums[mid])
                    tail = mid - 1;
                else head = mid + 1;
            }
            else if(nums[mid] == nums[head]){   // curcial!!! no longer monotone
                head++;
            }
            else{
                if(nums[mid] < target && target <= nums[tail])
                    head = mid + 1;
                else tail = mid - 1;
            }
        }
        return false;
    }
};
