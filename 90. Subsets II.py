class Solution(object):
    
    # recursive, set and backtracking: O(2^N) time & space
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def helper(nums, start, curr):
            self.ret.add(tuple(curr))
            if start == len(nums):
                return 
            for i in xrange(start, len(nums)):
                helper(nums, i + 1, curr + [nums[i]])
        self.ret = set()
        nums.sort()
        helper(nums, 0, [])
        return [list(sub) for sub in self.ret]
    
    # iterative, set and backtracking: O(2^N) time & space
    def subsetsWithDup(self, nums):
        ret = [[]]
        nums.sort()
        for i in xrange(len(nums)):
            temp = []
            for elem in ret:
                temp.append(elem + [nums[i]])
            ret += temp       # bug: should be extend instead of append
        return [list(x) for x in {tuple(y) for y in ret}]
    
    # !! iterative, backtracking: O(2^N) time & space
    def subsetsWithDup(self, nums):
        ret = [[]]
        nums.sort()
        i = 0
        while i < len(nums):
            sameCnt = 1   # number of same element
            while sameCnt + i < len(nums) and nums[sameCnt + i] == nums[i]:
                sameCnt += 1
                
            temp = []
            for elem in ret:
                for j in xrange(1, sameCnt + 1):
                    temp.append(elem + [nums[i]] * j)
                    
            ret += temp       # bug: should be extend instead of append
            i += sameCnt
            
        return ret
        
        