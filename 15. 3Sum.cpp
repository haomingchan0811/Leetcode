class Solution {
public:
    // hashtable: O(N2), 4.45%
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.empty()) ret;
        // bug: without sort and skip duplicates, there will be redundant triplet answers
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            while(i > 0 && nums[i] == nums[i - 1]) i++; // bug: see above
            unordered_map<int, int> complement;
            for(int j = i + 1; j < nums.size(); j++){
                if(complement.count(nums[j])){
                    vector<int> temp = {nums[i], complement[nums[j]], nums[j]};
                    ret.push_back(temp);
                    while(j + 1 < nums.size() && nums[j + 1] == nums[j]) j++; //bug: see above
                }
                else complement[-nums[i]-nums[j]] = nums[j];
            }
        }
        return ret;
    }

    // two pointers: O(N^2), 84.69%, 46ms (using STL::set -> TLE)
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            //bug: skip duplication for the first elem, should skip the tail of duplicates rather than the head
            while(i > 0 && nums[i] == nums[i - 1]) i++;
            int target = -nums[i];
            int head = i + 1;
            int tail = nums.size() - 1;
            while(head < tail){
                if(nums[head] + nums[tail] == target){
                    vector<int> temp {nums[i], nums[head], nums[tail]};
                    ans.push_back(temp);
                    // improvement: using set -> TLE, has to find another way to skip duplicates for the 2nd/3rd elem
                    while(head < tail && nums[head + 1] == nums[head]) head++;
                    while(head < tail && nums[tail - 1] == nums[tail]) tail--;
                    head++;
                    tail--;
                }
                else if(nums[head] + nums[tail] < target) head++;
                else tail--;
            }
        }
        return ans;
    }
};
