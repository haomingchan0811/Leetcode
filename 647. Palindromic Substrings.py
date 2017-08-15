class Solution(object):
    
    # brute force: O(2^N)time, TLE
    
    # dynamic programming: O(N2) time & space
    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """
        # check if whole string is palindrom (python might TLE for O(N2) time solution, sad)
        i, j, isPalindrome = 0, len(s) - 1, True
        while i < j:
            if s[i] != s[j]:
                isPalindrome = False
                break
            i, j = i + 1, j - 1
        if isPalindrome:
            return len(s)
        
        # dp[i][j]: longest length of parlindrome from i to j, inclusive
        dp = [[0 for i in xrange(len(s))] for j in xrange(len(s))]
        for length in xrange(1, len(s) + 1):
            for i in xrange(len(s) - length + 1):
                j = length + i - 1
                if i == j:          # base 1
                    dp[i][j] = 1       
                elif i + 1 == j:    # base 2
                    dp[i][j] = 2 if s[i] == s[j] else 1
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1] + (2 if s[i] == s[j] else 0))
        return dp[0][len(s) - 1]
        
        
    # TBD - dynamic programming: O(N2) time, O(N) space