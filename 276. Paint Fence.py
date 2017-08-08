class Solution(object):
    
    # dynamic programming: O(n) time, O(1) space
    def numWays(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        if n == 1:
            return k
        same = k
        diff = k * (k - 1)
        for i in xrange(2, n):   # bug: base case: n = 1 and n = 2
            same, diff = diff, (same + diff) * (k - 1)
        return same + diff if n else 0
        