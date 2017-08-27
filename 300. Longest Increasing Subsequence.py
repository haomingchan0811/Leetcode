class Solution(object):
    
    # dynamic programming: dp[i] = longest length ending in i
    # O(N2) time, O(N) space
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = [1 for i in range(len(nums))]
        ret = 1
        for end in xrange(1, len(nums)):
            for start in xrange(end):
                if nums[end] > nums[start]:
                    length[end] = max(length[end], length[start] + 1)
            ret = max(ret, length[end])
        return 0 if len(nums) == 0 else ret
    
    # !!?? dp with binary search: O(NlogN) time, O(N) space
    def lengthOfLIS(self, nums):
       
        