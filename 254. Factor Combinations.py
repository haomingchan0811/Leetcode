import math
class Solution(object):
    
    # dfs, backtracking: O(sqrt(N)*N) time, O(?) space
    def getFactors(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        def dfs(num, factor, curr):
            for i in xrange(factor, int(math.sqrt(num)) + 1):    # bug: right boundry
                if num % i == 0:
                    self.ret.append(curr + [i, num / i])
                    dfs(num / i, i, curr + [i])
        self.ret = []
        dfs(n, 2, [])
        return self.ret
                
        