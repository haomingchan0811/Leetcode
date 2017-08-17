class Solution(object):
    
    # back tracking: O(2^N) time & space
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        def helper(nums, i, curr, sum, target):
            if target == sum:
                self.ret.append(curr)
                return 
            if i == self.index or sum > target:
                return 
            for j in xrange(i, self.index):
                k = 1
                while nums[j] * k + sum <= target:
                    helper(nums, j + 1, curr + [nums[j]] * k, sum + nums[j] * k, target)
                    k += 1
        
        candidates.sort()
        self.index = None
        self.ret = []
        for i in xrange(len(candidates)):  # optimize: find the smallest num that's larger than target
            if candidates[i] > target:
                self.index = i
                break
        if self.index is None:
            self.index = len(candidates)
        helper(candidates, 0, [], 0, target)
        return self.ret
            
        
        