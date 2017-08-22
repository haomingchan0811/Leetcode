class Solution(object):
    
    # hash table: O(m + n) time, O(max(m,n)) space
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        count, ret = {}, []
        for num in nums1:
            count[num] = count.get(num, 0) + 1
        for num in nums2:
            if num in count and count[num] > 0:
                ret.append(num)
                count[num] -= 1
        return ret
    
    # two pointers: O(max(m,n)*log(max(m,n))) time, O(1) space
    def intersect(self, nums1, nums2):
        nums1.sort()
        nums2.sort()
        ret, i, j = [], 0, 0
        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                ret.append(nums1[i])
                i, j = i + 1, j + 1
            elif nums1[i] > nums2[j]:
                j += 1
            else:
                i += 1
        return ret
            
        