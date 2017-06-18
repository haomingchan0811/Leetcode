class Solution(object):
    
    # dynamic programming: O(N) time, O(1) space
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 3: return n
        oneStepBefore, twoStepBefore, ret = 2, 1, 0
        for i in xrange(3, n+1):
            ret = oneStepBefore + twoStepBefore
            oneStepBefore, twoStepBefore = ret, oneStepBefore
        return ret
        
        