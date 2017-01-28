class Solution {
public:
    // Hashset: O(N) time & space, 2.93%
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        if(nums.empty()) return ret;
        set<int> flag;
        for(auto num: nums) flag.insert(num);
        for(int i = 1; i <= nums.size(); i++)
            if(!flag.count(i))
                ret.push_back(i);
        return ret;
    }

    // for those already seen numbers, apply the application to the element with these numbers as indexes: negate/+n/...
    // O(N) time, without extra space, 35.82%, ok
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        if(nums.empty()) return ret;
        for(auto num: nums){
            int index = abs(num) - 1;  // bug: index = num - 1; num may already be negated -> index underflow
            if(nums[index] > 0)
                nums[index] = -nums[index];
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0)
                ret.push_back(i + 1);}
        return ret;
    }
};
