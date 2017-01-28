class Solution {
public:
    // binary search: 6ms worst O(n), avg: O(logN)
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return true;
            if(nums[mid] > nums[low]){
                if(nums[low] <= target && target < nums[mid]) high = mid;
                else low = mid + 1;
            }
            // different from 33.Search in Rotated Sorted Array I
            else if(nums[mid] == nums[low]){
                low += 1;
            }
            else{
                if(nums[mid] < target && target <= nums[high]) low = mid + 1;
                else high = mid;
            }
        }
        return false;
    }
};
