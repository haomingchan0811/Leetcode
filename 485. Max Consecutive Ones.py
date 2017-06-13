class Solution(object):
    
    # Brute force: O(N) time, O(1) space, 61.01%
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        count, maxCnt = int(nums[0] == 1), 0
        for i in xrange(1, len(nums)):
            if nums[i] == 1:
                count += 1
            else:
                count, maxCnt = 0, max(count, maxCnt)
        return max(maxCnt, count)
                