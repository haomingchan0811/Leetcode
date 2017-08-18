class Solution(object):
    
    # find the longest palindrome starting from head and do supplementation
    # O(N2) time, O(N) space, TLE
    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if s == s[::-1]:
            return s

        index = len(s) - 1
        while index >= 0:
            i, j = 0, index
            isPalin = True
            while i < j:
                if s[i] != s[j]:
                    isPalin = False
                    break
                i, j = i + 1, j - 1
            if isPalin:
                break
            index -= 1
        return s[:index:-1] + s
            
        