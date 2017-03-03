class Solution {
public:
    // binary search: O(logN) time, O(1)space, 4.47%, ok
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int head = 0, tail = nums.size() - 1;
        while(head <= tail){   // bug: miss the "="
            int mid = head + (tail - head) / 2;
            if(nums[mid] == target) return mid;

            if(nums[mid] >= nums[head]){   // important to check which part is monotonic
                if(nums[head] <= target && target < nums[mid])
                    tail = mid - 1;
                else head = mid + 1;
            }
            else{
                if(nums[mid] < target && target <= nums[tail])
                    head = mid + 1;
                else tail = mid - 1;
            }
        }
        return -1;
    }
};
