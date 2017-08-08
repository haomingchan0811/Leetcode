class Solution(object):
    
    # sort: O(NlogN) time, no space
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        if nums[0] != 0:
            return 0
        for i in xrange(1, len(nums)):
            if nums[i] != nums[i - 1] + 1:
                return nums[i] - 1
        return len(nums)
    
    # hash table: O(N) time & space
    def missingNumber(self, nums):
        nums = {num:1 for num in nums}
        for i in xrange(len(nums) + 1):
            if i not in nums:
                return i
    
    # sum and difference: O(N) time, O(1) space
    def missingNumber(self, nums):
        total = 0
        for i in xrange(len(nums)):
            total += i - nums[i]
        return total + len(nums)
    
    # xor: O(N) time, O(1) space
    def missingNumber(self, nums):
        ret = 0
        for i in xrange(len(nums)):
            ret ^= nums[i] ^ i
        return ret ^ len(nums)
            
