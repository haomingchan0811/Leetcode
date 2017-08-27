class Solution(object):
    
    # brute force: O(N3) time, O(N) space, TLE
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        def isPalindrome(s):
            i, j = 0, len(s) - 1
            while i < j:
                if s[i] != s[j]:
                    return False
                i, j = i + 1, j - 1
            return True
        cnt = 0
        for i in xrange(len(s)):
            for j in xrange(1, len(s) + 1 - i):
                if isPalindrome(s[i: i + j]):
                    cnt += 1
        return cnt
    
    # dynamic programming: dp[i][j] means whether s[i:j+1] is palindrome
    # O(N2) time, O(N2) space
    def countSubstrings(self, s):
        dp = [[True for i in range(len(s))] for j in range(len(s))]
        ret = 0
        for length in xrange(1, len(s) + 1):
            start, end = 0, length - 1
            while end < len(s):
                if length != 1:
                    dp[start][end] = dp[start + 1][end - 1] and s[start] == s[end]  
                ret += int(dp[start][end])
                start, end = start + 1, end + 1
        return ret
    
    # expand from center: O(N2) time, O(1) space
    def countSubstrings(self, s):
        def expand(s, left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                self.ret += 1
                left, right = left - 1, right + 1
        self.ret = 0
        for i in xrange(len(s)):
            expand(s, i, i)
            expand(s, i, i + 1)
        return self.ret
                
        
                