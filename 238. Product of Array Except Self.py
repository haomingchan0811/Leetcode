class Solution(object):
    
    # Two pass multiplication: O(N) time, O(1) space
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ret = [1] * len(nums)
        prod = 1
        for i in xrange(len(nums)):
            ret[i] = prod
            prod *= nums[i]
        prod = 1
        for i in xrange(len(nums)-1, -1, -1):
            ret[i] *= prod
            prod *= nums[i]
        return ret
        
    # Two pass multiplication: O(N) time, no space
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ret = [1] * len(nums)
        for i in xrange(1, len(nums)):
            ret[i] = ret[i-1] * nums[i-1]
        # key: ans[0] = 1 serves as a extra variable to accum product
        for i in xrange(len(nums)-1, 0, -1):
            ret[i] *= ret[0]
            ret[0] *= nums[i]
        return ret