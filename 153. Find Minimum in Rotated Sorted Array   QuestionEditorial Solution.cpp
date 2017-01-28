class Solution {
public:
    // binary search: O(logN), 24.13%, ok
    int findMin(vector<int>& nums) {
        int head = 0, tail = nums.size() - 1, mid;
        while(head <= tail){
            if(nums[tail] >= nums[head]) return nums[head];
            mid = head + (tail - head) / 2;
            if(nums[mid] < nums[head]) tail = mid;
            else if(nums[mid] > nums[tail]) head = mid + 1;
        }
        return 0;
    }
};
