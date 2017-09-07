class Solution(object):
    
    # recursive, back tracking: O(2^N) time, O(N) space
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def helper(nums, i, curr):
            self.ret.append(curr)
            if i == len(nums):
                return 
            for j in xrange(i, len(nums)):
                helper(nums, j + 1, curr + [nums[j]])
            
        self.ret = []
        helper(nums, 0, [])
        return self.ret
    
    # ! Iteratively: O(2^N) time, O(N) space
    def subsets(self, nums):
        ret = [[]]
        for num in nums:
            temp = []
            for elem in ret:
                temp.append(elem + [num])
            ret += temp
        return ret