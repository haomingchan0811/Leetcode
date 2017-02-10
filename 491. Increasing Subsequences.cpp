class Solution {
public:
    // iterative, find subsequece for every char: O(N3)time, 64.51%
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ret;  // use set to avoid duplicate vectors
        if(nums.empty()) return vector<vector<int>>();
        for(int i = 0; i < nums.size() - 1; i++){
            vector<vector<int>> temp;  // with nums[i] as head, all subseq that matches
            int head = nums[i];
            for(int j = i + 1; j < nums.size(); j++){
                int curSize = temp.size();  // bug: temp size changes dynamically, should pin it first
                for(int k = 0; k < curSize; k++){
                    if(temp[k][temp[k].size() - 1] <= nums[j]){
                        vector<int> newSub = temp[k];
                        newSub.push_back(nums[j]);
                        temp.push_back(newSub);
                    }
                }
                if(nums[j] >= head)
                    temp.push_back(vector<int>{head, nums[j]});
            }
            ret.insert(temp.begin(), temp.end());
        }
        vector<vector<int>> ans(ret.begin(), ret.end());
        return ans;
    }

    // backtracking & recursive, find subsequece for every char: O(N3)time, 64.51%
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ret;  // use set to avoid duplicate vectors
        vector<int> curr;
        helper(ret, curr, 0, nums);
        return vector<vector<int>>(ret.begin(), ret.end());
    }

    void helper(set<vector<int>>& ret, vector<int> curr, int index, vector<int> nums){
        if(curr.size() >= 2)
            ret.insert(curr);
        for(int i = index; i < nums.size(); i++){
            // bug: "i = 0" -> "curr.empty()"
            if(curr.empty() || curr[curr.size() - 1] <= nums[i]){
                curr.push_back(nums[i]);
                helper(ret, curr, i + 1, nums);
                curr.pop_back();
            }
        }
    }
};
