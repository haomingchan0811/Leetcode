class Solution {
public:
    // sequential scan: O(N)time, O(1)space, 16.47%
    int findPeakElement(vector<int>& nums) {
        int ret = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] >= nums[i - 1])
                ret = i;
            else break;
        }
        return ret;
    }
    
    // binary search: O(logN)time, O(1)space, 16.47%
    int findPeakElement(vector<int>& nums) {
        int head = 0, tail = nums.size() - 1;
        while(head < tail){
            int mid = head + (tail - head) / 2;
            if(mid > 0 && nums[mid - 1] > nums[mid]) tail = mid - 1;
            else if(mid + 1 < nums.size() && nums[mid + 1] > nums[mid]) head = mid + 1;
            else return mid;
        }
        return head;
    }
};