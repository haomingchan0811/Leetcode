class Solution(object):
    
    # Brute force: O(N) time, O(1) space, 43.8%
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        bitStr, ret = bin(num)[2:], 0
        for i in xrange(len(bitStr)-1, -1, -1):
            ret += 1 << (len(bitStr)-1-i) if bitStr[i] == '0' else 0
        return ret
        
    # Exclusive or: O(N) time, O(1) space, 39.31%
    def findComplement(self, num):
        i = 1
        while i <= num:
            i = i << 1   
        return (i - 1) ^ num