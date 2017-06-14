class Solution(object):
    
    # Brute force: O(N) time, O(1) space, 95.15%
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x == 0: return True  # bug: 0
        if x < 0 or x % 10 == 0: return False  # bug: negative num 
        rev, ori = 0, x
        while x:
            rev, x = rev * 10 + x % 10, x / 10
        return rev == ori
        
    # reverse only half: O(N) time, O(1) space, 31.60%
    def isPalindrome(self, x):
        if x >= 0 and x < 10: return True
        if x < 0 or x % 10 == 0: return False  
        rev = 0
        while len(str(rev)) < len(str(x)):
            rev, x = rev * 10 + x % 10, x / 10
        return rev == x if len(str(rev)) == len(str(x)) else rev / 10 == x
    
    # reverse only half without string: O(N) time, O(1) space, 75.62%
    def isPalindrome(self, x):
        if x < 0 or (x > 0 and x % 10 == 0): return False  
        rev = 0
        while rev < x:
            rev, x = rev * 10 + x % 10, x / 10
        return rev == x or rev / 10 == x