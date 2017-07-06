class Solution(object):
    
    # brute force: O(N2) time, O(1) space, TLE
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ret = float('-inf')
        for i in xrange(len(nums)):
            for j in xrange(i, len(nums)):
                prod = reduce(lambda x, y: x*y, nums[i: j+1])
                ret = max(ret, prod)
        return ret
    
    # !! dynamic programming: O(N) time, O(1) space
    def maxProduct(self, nums):
        # maximum: maximum product ending with i now
        if len(nums) == 0: return 0
        ret, maximum, minimum = nums[0], nums[0], nums[0]
        for num in nums[1:]:
            if num < 0:
                maximum, minimum = minimum, maximum
            maximum = max(num, num * maximum)
            minimum = min(num, num * minimum)
            ret = max(ret, maximum)
        return ret