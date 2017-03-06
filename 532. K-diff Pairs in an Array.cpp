class Solution {
public:
    // sort and binary search: O(NlogN)time, O(N)space, ok
    int findPairs(vector<int>& nums, int k) {
        if(nums.empty() || k < 0) return 0;
        int ret = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int target = nums[i] + k;
            int head = i + 1, tail = nums.size();
            while(head <= tail){
                int mid = head + (tail - head) / 2;
                if(nums[mid] == target){ ret++; break;}
                else if(nums[mid] < target) head = mid + 1;
                else tail = mid - 1;
            }
            while(i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return ret;
    }

    // hashmap: O(N)time & space, ok
    int findPairs(vector<int>& nums, int k) {
        if(nums.empty() || k < 0) return 0; // bug: k < 0
        int ret = 0;
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++)
            map[nums[i]]++;
        if(k == 0){
            for(auto pair: map)
                ret += pair.second > 1;
        }
        else{
            // bug: access a key that doesn't exist with [] will
            // automatically insert the key into the map
            for(auto pair: map)
                ret += (map.count(pair.first + k) && map[pair.first + k] > 0);
        }
        return ret;
    }
};
