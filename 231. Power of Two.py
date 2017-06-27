class Solution(object):
    
    # recursion: O(logN) time, no space
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n <= 0: return False
        if n == 1: return True
        return n % 2 == 0 and self.isPowerOfTwo(n / 2)
    
    # iterative: O(logN) time, no space
    def isPowerOfTwo(self, n):
        if n <= 0: return False
        while n != 1:
            if n % 2 != 0: return False
            n /= 2
        return True
    
    # bit manipulation: O(1) time, no space
    def isPowerOfTwo(self, n):
        return n > 0 and n & (n-1) == 0

        