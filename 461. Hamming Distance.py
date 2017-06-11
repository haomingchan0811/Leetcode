class Solution(object):
    
    # Bit manipulation: O(N) time, O(1) space, 77.90%
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        dist = 0
        for i in xrange(32):
            dist += ((1 << i) & x > 0) != ((1 << i) & y > 0)
        return dist
        
    # Bit manipulation: O(N) time, O(1) space, 59.69%
    def hammingDistance(self, x, y):
        xor, dist = x ^ y, 0
        for i in xrange(32):
            dist += ((1 << i) & xor > 0)
        return dist
    
    # Bit manipulation: O(N) time, O(1) space, 18.75%
    def hammingDistance(self, x, y):
        return bin(x ^ y).count('1')