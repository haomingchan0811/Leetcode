class Solution(object):
    
    # # backtracking: O(2^N) time, O(1) space, TLE
    # def canPartition(self, nums):
    #     """
    #     :type nums: List[int]
    #     :rtype: bool
    #     """
    #     def helper(nums, i, curr):
    #         if curr == self.half:
    #             return True
    #         elif i == len(nums) or curr > self.half:  # early stopping
    #             return False
    #         for j in xrange(i, len(nums)):
    #             if helper(nums, j + 1, curr + nums[j]):
    #                 return True
    #         return False
    #     nums.sort()
    #     self.half = sum(nums) * 1.0 / 2
    #     if int(self.half) != self.half:
    #         return False
    #     return helper(nums, 0, 0)
    
    # backtracking with memorization: O(N2) time, O(N2) space
    def canPartition(self, nums):
        def helper(nums, i, curr):
            if curr == self.half:
                return True
            elif i == len(nums) or curr > self.half:  # early stopping
                return False
            if (i, curr) in self.memo:
                return self.memo[(i, curr)]
            for j in xrange(i, len(nums)):
                if helper(nums, j + 1, curr + nums[j]):
                    self.memo[(i, curr)] = True
                    return True
            self.memo[(i, curr)] = False
            return False
        
        self.half = sum(nums) * 1.0 / 2
        if int(self.half) != self.half:
            return False
        nums.sort()
        self.memo = {}
        return helper(nums, 0, 0)

    # dynamic programming: dp[n] means whether there's a subset whose sum is n
    # O(N2) time, O(N) space
    def canPartition(self, nums):
        sums = sum(nums) 
        if sums & 1:
            return False
        half = sums / 2
        dp = [False for i in range(half + 1)]
        dp[0] = True  # base case
        for num in nums:
            # for j in xrange(half, 0, -1):   # bug
            for j in xrange(half, num - 1, -1):
                dp[j] = dp[j] or dp[j - num]
        return dp[half]
        
    
   
        