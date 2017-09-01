class Solution(object):
    
#     # backtracking: O(2^N) time, O(1) space, TLE 
#     def combinationSum4(self, nums, target):
#         """
#         :type nums: List[int]
#         :type target: int
#         :rtype: int
#         """
#         def helper(nums, i, target):
#             if target == 0:
#                 self.ret += 1
#             elif target < 0:
#                 return
#             else:
#                 for j in xrange(i, len(nums)):
#                     helper(nums, 0, target - nums[j])
        
#         self.ret = 0
#         helper(nums, 0, target)
#         return self.ret

    # backtracking with memorization: O(N2) time, O(N) space 
    def combinationSum4(self, nums, target):
        def helper(nums, i, target):
            if target == 0:
                self.memo[(i, target)] = 1
            elif target < 0:
                return 0
            else:
                if (i, target) not in self.memo:
                    count = 0
                    for j in xrange(i, len(nums)):
                        count += helper(nums, 0, target - nums[j])
                    self.memo[(i, target)] = count
            return self.memo[(i, target)]
        
        self.ret = 0
        self.memo = {}
        return helper(nums, 0, target)
    
    # !! dynamic programming: O(N2) time, O(N) space 
    def combinationSum4(self, nums, target):
        nums.sort()
        dp = [0 for i in range(target + 1)]  # how many ways to construct i
        dp[0] = 1                            # base case
        for i in xrange(1, target + 1):
            for num in nums:
                if num > i:
                    break
                dp[i] += dp[i - num]
        return dp[target]
        