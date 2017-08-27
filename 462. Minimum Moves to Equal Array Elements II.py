class Solution(object):
    
    # sort and find median: O(NlogN) time, O(1) space
    def minMoves2(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        nums.sort()
        mid = nums[len(nums) / 2]
        ret = 0
        for num in nums:
            ret += abs(num - mid)
        return ret