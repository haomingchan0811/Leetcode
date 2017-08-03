class Solution(object):
    
    # brute force: O(mn) time, O(1) space
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        ret = []
        for i in xrange(len(nums1)):
            if nums1[i] in ret:
                continue
            for j in xrange(len(nums2)):
                if nums1[i] == nums2[j]:
                    ret.append(nums1[i])
                    break
        return ret
    
    # set: O(m+n) time, O(m+n) space
    def intersection(self, nums1, nums2):
        set1, set2 = set(nums1), set(nums2)
        return [num for num in set1 if num in set2]
    
    # pythonic set: O(m+n) time, O(m+n) space
    def intersection(self, nums1, nums2):
        set1, set2 = set(nums1), set(nums2)
        return list(set1.intersection(set2))
    
    # hash table: O(m+n) time, O(min(m, n)) space
    def intersection(self, nums1, nums2):
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        cnt = {num:1 for num in nums1}
        ret = []
        for num in nums2:
            if num in cnt and num not in ret:
                ret.append(num)
        return ret
        