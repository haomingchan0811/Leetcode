class Solution:
    
    # Brute force: O(1) time & space
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        bit = bin(n)[2:].zfill(32)
        return sum(int(bit[i]) * (2 ** i) for i in xrange(32))
        
    # Pythonic: O(1) time & space
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        bit = bin(n)[2:].zfill(32)
        return int(bit[::-1], 2)s