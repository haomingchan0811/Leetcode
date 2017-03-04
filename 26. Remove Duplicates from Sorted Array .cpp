class Solution {
public:
    // two pointers: O(N)time, O(1)space, 52.71%, ok
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int curr = 0;  // pointer of the last distinct value
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[curr]){
                swap(nums[++curr], nums[i]);
            }
        }
        return curr + 1;
    }

    // two pointers without swap: O(N)time, O(1)space, 52.71%, ok
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int replace = 1;  // pointer of the next replaced position
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[replace - 1]){
                nums[replace++] = nums[i];
            }
        }
        return replace;
    }
};
