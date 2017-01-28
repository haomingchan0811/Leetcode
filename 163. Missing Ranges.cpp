class Solution {
public:
    // one pass: O(N)time & space, 17.43%, ok
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ret;
        if(nums.size()){
            if(nums[0] != lower) getRange(ret, lower, nums[0] - 1);
            lower = nums[0] == INT_MAX? INT_MAX: nums[0] + 1;
            for(int i = 1; i < nums.size(); i++){
                // bug: "nums[i] != lower", wrong if duplicates exists
                if(nums[i] > lower) getRange(ret, lower, nums[i] - 1);
                lower = nums[i] == INT_MAX? INT_MAX: nums[i] + 1;
            }
        }
        if(lower != INT_MAX && lower <= upper)  // bug: int may overflow by increment lower
            getRange(ret, lower, upper);
        return ret;
    }

    void getRange(vector<string>& ret, int lower, int upper){
        ret.push_back(lower == upper? to_string(lower) : to_string(lower) + "->" + to_string(upper));
    }
};
