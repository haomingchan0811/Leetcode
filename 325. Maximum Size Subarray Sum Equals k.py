class Solution(object):
    
    # # hash table: O(N3) time, O(1) space, TLE
    # def maxSubArrayLen(self, nums, k):
    #     """
    #     :type nums: List[int]
    #     :type k: int
    #     :rtype: int
    #     """
    #     ret = 0
    #     for i in xrange(len(nums)):
    #         for l in xrange(1, len(nums) + 1 - i):
    #             subSum = sum(nums[i: i + l])
    #             if subSum == k:
    #                 ret = max(ret, l)
    #     return ret
    
    # # dynamic programming: O(N2) time, O(N2) space, TLE
    # def maxSubArrayLen(self, nums, k):
    #     ret = 0
    #     sub = [[num for num in nums] for i in xrange(len(nums))]    #[i, j] -> sum of interval
    #     for i in xrange(len(nums)):
    #         for j in xrange(i, len(nums)):
    #             if i != j:
    #                 sub[i][j] = sub[i][j - 1] + nums[j]
    #             if sub[i][j] == k:
    #                 ret = max(ret, j - i + 1)
    #     return ret
    
    # !! hash table: O(N) time, O(N2) space, 
    def maxSubArrayLen(self, nums, k):
        ret = 0
        for i in xrange(1, len(nums)):   # nums[i] becomes sum of nums[0~i]
            nums[i] += nums[i - 1]
        length = {0: 0}
        for i in xrange(len(nums)):
            if nums[i] not in length:
                length[nums[i]] = i + 1
            if (nums[i] - k) in length:
                ret = max(i - length[nums[i] - k] + 1, ret)
        return ret