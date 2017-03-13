class Solution {
public:
    // recursive: 15.17%, ok
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.empty()) return ret;
        if(nums.size() == 1){
            ret.push_back(vector<int>(1, nums[0]));
            return ret;
        }
        unordered_set<int> used;  // deal with duplicates
        for(int i = 0; i < nums.size(); i++){
            vector<int> rest;
            if(used.count(nums[i])) continue;
            used.insert(nums[i]);
            for(int j = 0; j < nums.size(); j++)
                if(j != i) rest.push_back(nums[j]);
            vector<vector<int>> remain = permuteUnique(rest);
            for(int j = 0; j < remain.size(); j++){
                remain[j].push_back(nums[i]);
                ret.push_back(remain[j]);
            }
        }
        return ret;
    }

    // recursive, without copying vector: 6.53%, ok
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.empty()) return ret;
        helper(ret, nums, 0, vector<int>());
        return ret;
    }

    void helper(vector<vector<int>>& ret, vector<int>& nums, int begin, vector<int> temp){
        if(temp.size() == nums.size()) {
            ret.push_back(temp);
            return;
        }
        unordered_set<int> used;  // deal with duplicates
        for(int i = begin; i < nums.size(); i++){
            if(used.count(nums[i])) continue;
            used.insert(nums[i]);
            swap(nums[i], nums[begin]);
            temp.push_back(nums[begin]);
            helper(ret, nums, begin + 1, temp);
            temp.pop_back();
            swap(nums[i], nums[begin]);
        }
    }
};
