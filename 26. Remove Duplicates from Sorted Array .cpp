class Solution {
public:
    // two pointers: 45ms
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int index = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[index] != nums[i]){
                index++;
                nums[index] = nums[i];
            }
        }
        return index + 1;
    }

    // two pointers: 46ms
    int removeDuplicates(vector<int>& nums){
        if(nums.size() <= 1) return nums.size();
        int cnt = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]) cnt++;
            else nums[i - cnt] = nums[i];
        }
        return nums.size() - cnt;
    }

    // two pointers: 23ms
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int index = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[index - 1] != nums[i]){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};
