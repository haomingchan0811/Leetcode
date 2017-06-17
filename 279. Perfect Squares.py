import math
class Solution(object):
  
    # dynamic programming: O(N) time & space
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        if int(math.sqrt(n)) ** 2 == n: return 1
        ret = [1 if int(math.sqrt(i)) ** 2 == i else float('inf') for i in xrange(n+1)]
        for i in xrange(n+1):
            if ret[i] == 1: continue
            for j in xrange(1, int(math.sqrt(i))+1):
                ret[i] = min(ret[i], ret[i-j**2] + 1)
        return ret[n]
        
    # BFS?