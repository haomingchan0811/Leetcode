class Solution(object):
    
    # brute force: O(N2) time, O(1) space, TLE
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        for i in xrange(len(nums)):
            for j in xrange(i + 1, len(nums)):
                if nums[i] == nums[j]:
                    return True
        return False
    
    # hash table: O(N) time & space
    def containsDuplicate(self, nums):
        count = {}
        for num in nums:
            if num in count:
                return True
            count[num] = 1
        return False
    
    # hash set: O(N) time & space
    def containsDuplicate(self, nums):
        count = set(nums)
        return len(count) != len(nums)
    
    # sort: O(NlogN) time, O(1) space
    def containsDuplicate(self, nums):
        nums.sort()
        prev = None
        for num in nums:
            if prev is not None and num == prev:
                return True
            prev = num
        return False
        