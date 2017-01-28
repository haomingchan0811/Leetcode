class Solution {
public:
    // two pointers: 13ms
    // This is a general solution, 2 can be repleaced by any integer k
    // to realize the problem of allowing k duplicates in the sorted array
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        int index = 2;
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] != nums[index - 2]){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};
