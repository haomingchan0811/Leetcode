class Solution {
public:
    // Two pointers: O(m+n)time, O(m+n) space, 33.07%, ok
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ret;
        int i = 0, j = 0;
        while(i < m || j < n){
            if(i == m)
                ret.push_back(nums2[j++]);
            else if(j == n)
                ret.push_back(nums1[i++]);
            else if(nums1[i] <= nums2[j])
                ret.push_back(nums1[i++]);
            else ret.push_back(nums2[j++]);
        }
        nums1 = ret;
    }

    // Two pointers: O(m+n)time, no space, 33.07%, ok
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(m > 0 && n > 0){
            if(nums1[m - 1] <= nums2[n - 1])
                nums1[m + n - 1] = nums2[n-- - 1];
            else nums1[m + n - 1] = nums1[m-- - 1];
        }
        while(n) nums1[n - 1] = nums2[n-- - 1];
    }
};
