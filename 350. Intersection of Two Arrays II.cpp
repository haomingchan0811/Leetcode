class Solution {
public:
    // hashmap: O(m+n)time & space, 57.37%, ok
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int, int> map;
        if(nums1.empty() || nums2.empty()) return ret;
        for(auto n: nums1) map[n]++;
        for(auto n: nums2){
            if(map.count(n) && map[n] > 0){
                map[n]--;
                ret.push_back(n);
            }
        }
        return ret;
    }
    
    // sort and two pointers, O(max(mlogm, nlogn)) time, O(1)space, 18.12%
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        if(nums1.empty() || nums2.empty()) return ret;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]){
                ret.push_back(nums1[i]);
                i++; j++;
            }
            else if(nums1[i] > nums2[j])
                j++;
            else i++;
        }
        return ret;
    }
};