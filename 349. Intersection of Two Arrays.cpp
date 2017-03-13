class Solution {
public:
    // two pointers: O(max(mlogm, nlogn))time, O(1)space, 58.27%, ok
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        if(nums1.empty() || nums2.empty()) return ret;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for(int i = 0, j = 0; i < nums1.size() && j < nums2.size();){
            if(nums1[i] == nums2[j]){
                ret.push_back(nums1[i]);
                while(i+1 < nums1.size() && nums1[i+1] == nums1[i]) i++;
                while(j+1 < nums2.size() && nums2[j+1] == nums2[j]) j++;
                i++; j++;
            }
            else if(nums1[i] < nums2[j]) i++;
            else j++;
        }
        return ret;
    }

    // hashset/hashmap: O(m + n)time, O(m or n)space, 58.27%, ok
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        if(nums1.empty() || nums2.empty()) return ret;
        unordered_set<int> elem(nums1.begin(), nums1.end());
        for(auto n: nums2){
            if(elem.count(n)){
                ret.push_back(n);
                elem.erase(n);
            }
        }
        return ret;
    }
};
