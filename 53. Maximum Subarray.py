class Solution(object):
    
#     # range sum brute force: O(n2) time, O(1) space, TLE
#     def maxSubArray(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
#         if len(nums) < 2:
#             return sum(nums)
#         ret = nums[0]
#         for i in xrange(1, len(nums)):
#             if nums[i] > ret:     # check individual
#                 ret = nums[i]
#             nums[i] += nums[i - 1]
        
#         for l in xrange(2, len(nums) + 1):
#             ret = max(ret, nums[l - 1])
#             start = 0
#             while start + l <= len(nums):
#                 end = start + l - 1
#                 ret = max(ret, nums[end] - nums[start])
#                 start += 1
#         return ret

    # dp: O(n) time, O(1) space
    def maxSubArray(self, nums):
        if len(nums) < 2:
            return sum(nums)
        prev, ret = nums[0], nums[0]
        for i in xrange(1, len(nums)):
            prev = nums[i] + max(0, prev)   # use previous elems or not
            ret = max(ret, prev)
        return ret
        
            