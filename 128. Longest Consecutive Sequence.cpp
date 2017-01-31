class Solution {
public:
    // sort: O(NlogN)time, O(1)space, 3.93%
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int i = 0, j = 1, ret = 1;
        for(j; j < nums.size(); j++){
            if(nums[j] > nums[j - 1] + 1){ // bug: "(nums[j] != nums[j - 1] + 1", duplicates
                ret = max(ret, nums[j - 1] - nums[i] + 1);
                i = j;
            }
        }
        return max(ret, nums[j - 1] - nums[i] + 1);
    }

    // unordered_set: O(1) for insertion, retrieval and deletion
    // O(N)time & space, 81.59%, ok
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ret = 0;
        unordered_set<int> unique;
        for(int i = 0; i < nums.size(); i++)
           unique.insert(nums[i]);
        for(int i = 0; i < nums.size(); i++){
            if(unique.empty()) break;
            if(unique.find(nums[i]) != unique.end()){  // find each consecutive truck
                int head = nums[i] - 1, tail = nums[i] + 1;
                unique.erase(nums[i]);
                while(unique.find(head) != unique.end())
                    unique.erase(head--);
                while(unique.find(tail) != unique.end())
                    unique.erase(tail++);
                ret = max(ret, tail - head - 1);
            }
        }
        return ret;
    }
};
