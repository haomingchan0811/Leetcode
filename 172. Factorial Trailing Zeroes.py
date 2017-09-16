class Solution(object):
    
    # find number of 5s: O(logN) time, O(1) space
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = 0
        while n / 5:
            count += n / 5
            n /= 5
        return count 
        