class Solution {
public:
    // swap: O(n)time & space, 18.55%, bad
    vector<int> findDuplicates(vector<int>& nums) {
        set<int> ret;
        if(nums.empty()) return vector<int>(0, 0);
        for(int i = 0; i < nums.size(); i++){
            while(nums[i] != i + 1){
                if(nums[i] == nums[nums[i] - 1]){
                    ret.insert(nums[i]);
                    break;
                }
                else swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return vector<int>(ret.begin(), ret.end());
    }

    // hashtable: O(n)time & space, 72.89%, ok
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret, map(nums.size() + 1, 0);
        if(nums.empty()) return ret;
        for(auto num: nums) map[num]++;
        for(int i = 1; i <= nums.size(); i++){
            if(map[i] > 1)
                ret.push_back(i);
        }
        return ret;
    }

    // hashtable: O(n)time, no space, 72.89%, ok
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        if(nums.empty()) return ret;
        for(auto num: nums){
            if(nums[abs(num) - 1] < 0)
                ret.push_back(abs(num));
            else nums[abs(num) - 1] *= -1;
        }
        return ret;
    }
};
