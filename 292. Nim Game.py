class Solution(object):
    
    # pattern: O(1) time, no space, 89.11%
    def canWinNim(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return bool(n % 4)