class Solution {
public:
    // Two pointers: O(N), 19.31%, ok
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int head = 0, tail = nums.size() - 1;
        int count = 0;
        while(head <= tail){
            while(head <= tail && nums[head] != val) head++;
            while(head <= tail && nums[tail] == val) {tail--; count++;};
            if(head < tail) {
                swap(nums[head++], nums[tail--]);
                count++;
            }
        }
        nums.resize(nums.size() - count);
        return nums.size();
    }

    // Two pointers, more elegant: O(N), 19.31%, ok
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int valid = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[valid] = nums[i];
                valid++;
            }
        }
        return valid;
    }

    // Two pointers, when elements to remove are rare, avoid unnecessary copy: O(N), 19.31%, ok
    int removeElement(int[] nums, int val) {
        int i = 0;
        int n = nums.length;
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                n--; // reduce array size by one
            }
            else i++;
        }
        return n;
    }
};
