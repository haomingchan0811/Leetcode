class Solution(object):
    
    # brute force: O(max(m,n)) time, O(m+n) space
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        merged, i, j = [], 0, 0
        while i < m and j < n:
            if nums1[i] <= nums2[j]:
                merged.append(nums1[i])
                i += 1
            else:
                merged.append(nums2[j])
                j += 1
        for k in xrange(i, m):
            merged.append(nums1[k])
        for k in xrange(j, n):
            merged.append(nums2[k])
        while len(nums1):
            nums1.pop()
        for num in merged:
            nums1.append(num)
    
    # two pointers, in place: O(max(m,n)) time, O(1) space
    def merge(self, nums1, m, nums2, n):
        while m > 0 and n > 0:
            if nums1[m - 1] >= nums2[n - 1]:
                nums1[m + n - 1] = nums1[m - 1]
                m -= 1
            else:
                nums1[m + n - 1] = nums2[n - 1]
                n -= 1
        if n > 0:
            nums1[:n] = nums2[:n]
        