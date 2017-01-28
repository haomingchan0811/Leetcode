class Solution {
public:
    // recursive: 7.25%, ok
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.empty()) return ret;
        if(nums.size() == 1){
            ret.push_back(vector<int>(1, nums[0]));
            return ret;
        }
        for(int i = 0; i < nums.size(); i++){
            vector<int> rest;
            for(int j = 0; j < nums.size(); j++)
                if(j != i) rest.push_back(nums[j]);
            vector<vector<int>> remain = permute(rest);
            for(int j = 0; j < remain.size(); j++){
                remain[j].insert(remain[j].begin(), nums[i]);
                ret.push_back(remain[j]);
            }
        }
        return ret;
    }
};
