class Solution {
public:
    // O(M+N), 60.64%, ok
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int i = 0, j = 0, m = nums1.size(), n = nums2.size();
        while(i < m && j < n){
            if(nums1[i] <= nums2[j]) nums.push_back(nums1[i++]);
            else nums.push_back(nums2[j++]);
        }
        if(i != m)
            while(i < m) nums.push_back(nums1[i++]);
        if(j != n)
            while(j < n) nums.push_back(nums2[j++]);
        int size = m + n;
        if(size & 1) return nums[size / 2];
        else return (nums[size / 2 - 1] + nums[size / 2]) * 1.0 / 2;
    }

    // binary search: O(log(M+N)),
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {


    }

};
