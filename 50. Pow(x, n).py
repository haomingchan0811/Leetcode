class Solution(object):
    
    # # brute force: O(N) time, O(1) space, TLE
    # def myPow(self, x, n):
    #     """
    #     :type x: float
    #     :type n: int
    #     :rtype: float
    #     """
    #     ret, positive = 1, True
    #     if n < 0:                   # bug: negative exponent
    #         positive, n = False, -n
    #     for i in xrange(n):
    #         ret *= x
    #     return ret if positive else 1 / ret
    
    # ! binary search, dfs: O(logN) time, O(1) space
    def myPow(self, x, n):
        if n == 0:
            return 1
        if n < 0:
            x, n = 1 / x, -n
        return x * self.myPow(x * x, n / 2) if n & 1 else self.myPow(x * x, n / 2)
    
    # ! binary search, iterative: O(logN) time, O(1) space
    def myPow(self, x, n):
        ret = 1
        if n < 0:
            x, n = 1 / x, -n
        while n:
            if n & 1:
                ret *= x   # key
            x *= x
            n >>= 1
        return ret
            
        
        