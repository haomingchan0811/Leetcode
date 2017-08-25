class Solution(object):
    
    # backtracking: O(2^N) time, O(1) space, TLE
    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        def helper(nums, i, sum, S):
            if i == len(nums):
                self.ret += 1 if sum == S else 0
            else:
                helper(nums, i + 1, sum + nums[i], S)
                helper(nums, i + 1, sum - nums[i], S)
        self.ret = 0
        helper(nums, 0, 0, S)
        return self.ret
    
    # !!!! backtracking with memorization: O(rangeOfSum * N) time, O(rangeOfSum * N) space
    def findTargetSumWays(self, nums, S):
        def helper(nums, i, sum, S):
            if i == len(nums):
                return 1 if sum == S else 0
            else:
                if self.memo[i].get(sum, None) is not None:
                    return self.memo[i][sum]
                add = helper(nums, i + 1, sum + nums[i], S)
                subtract = helper(nums, i + 1, sum - nums[i], S)
                self.memo[i][sum] = add + subtract
                return self.memo[i][sum]
        self.memo = {i: {} for i in xrange(len(nums))}
        return helper(nums, 0, 0, S)
    
    # hash table, dynamic programming: O(N2) time, O(1) space, TLE
    def findTargetSumWays(self, nums, S):
        count = {0: 1}
        for i in xrange(len(nums)):
            temp = {}
            for sum, cnt in count.items():
                temp[sum + nums[i]] = temp.get(sum + nums[i], 0) + cnt
                temp[sum - nums[i]] = temp.get(sum - nums[i], 0) + cnt
            count = temp
        return count.get(S, 0)        