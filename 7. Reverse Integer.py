class Solution(object):
    
    # brute force: O(n) time, O(1) space
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        neg = True if x < 0 else False
        ret, x, boundry = 0, abs(x), 2 ** 31
        while x:
            ret = ret * 10 + x % 10
            x /= 10
            if ret > boundry:
                return 0
        return -ret if neg else ret
        