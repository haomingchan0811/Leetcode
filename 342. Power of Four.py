class Solution(object):
    
    # recursion: O(log_4N) time, no space
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0: return False
        if num == 1: return True
        return num % 4 == 0 and self.isPowerOfFour(num / 4)
    
    # math, binary form is of odd len with only one heading 1 and 0 for the tail
    # O(1) time, no space
    def isPowerOfFour(self, num):
        if num <= 0: return False
        return num & (num-1) == 0 and len(bin(num)[2:]) % 2 == 1
        