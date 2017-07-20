class Solution(object):
    
    # recursive, back tracking: O(2^N) time, O(N) space
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def dfs(nums, curr, ret):
            ret.append(curr)
            for j in range(len(nums)):
                dfs(nums[j + 1:], curr + [nums[j]], ret)
        
        ret = []
        dfs(nums, [], ret)
        return ret
    
    # ! Iteratively: O(2^N) time, O(N) space
    def subsets(self, nums):
        ret = [[]]
        for num in nums:
            temp = []
            for elem in ret:
                temp.append(elem + [num])
            ret += temp
        return ret