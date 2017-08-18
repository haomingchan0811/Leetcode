class Solution(object):
    
    # # brute force: O(N3) time, O(1) space, TLE
    # def maximumProduct(self, nums):
    #     """
    #     :type nums: List[int]
    #     :rtype: int
    #     """
    #     ret = float('-inf')
    #     for i in xrange(len(nums)):
    #         for j in xrange(i + 1, len(nums)):
    #             for k in xrange(j + 1, len(nums)):
    #                 temp =nums[i] * nums[j] * nums[k]
    #                 if temp > ret:
    #                     ret = temp
    #     return ret
    
    # sort: O(NlogN) time, O(1) space, TLE
    def maximumProduct(self, nums):
        nums.sort()
        if len(nums) == 3:
            return reduce(lambda x, y: x * y, nums)
        # consider cases when num is negative: two smallest negative * one largest positive 
        return max(nums[-1] * nums[-2] * nums[-3], nums[0] * nums[1] * nums[-1])
    
    
    # single scan to replace sort: O(N) time, O(1) space
    def maximumProduct(self, nums):
        min1, min2, max1, max2, max3 = float('inf'), float('inf'), float('-inf'), float('-inf'), float('-inf')
        for num in nums:
            if num < min1:
                min1, min2 = num, min1
            elif num < min2:
                min2 = num
                
            if num > max1:
                max3, max2, max1 = max2, max1, num
            elif num > max2:
                max3, max2 = max2, num
            elif num > max3:
                max3 = num
        return max(min1 * min2 * max1, max1 * max2 * max3)

        