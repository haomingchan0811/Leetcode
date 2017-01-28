class Solution {
public:
    // O(N), 48.01%, ok
    void wiggleSort(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            // if(((i & 1) && (nums[i] < nums[i - 1])) || (!(i & 1) && (nums[i] > nums[i - 1])))
            if((i & 1) ^ (nums[i] > nums[i - 1]))  // more concise repr -> 62.76%
                swap(nums[i], nums[i - 1]);
        }
    }
};
