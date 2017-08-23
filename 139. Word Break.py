class Solution(object):
    
    # backtracking: O(N^N) time, O(N) space, TLE
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        if s == '':
            return True
        for w in wordDict:
            if len(w) <= len(s) and w == s[:len(w)]:
                if self.wordBreak(s[len(w):], wordDict):
                    return True
        return False
    
    # !! backtracking with memorization: O(N2) time, O(N) space, TLE
    def wordBreak(self, s, wordDict):
        def helper(s, start, wordDict):
            if start == len(s):
                return True
            if self.memo.get(start, None) is not None:
                return self.memo[start]
            for end in xrange(start, len(s)):
                if s[start:end + 1] in wordDict and helper(s, end + 1, wordDict):
                    self.memo[start] = True
                    return True
            self.memo[start] = False
            return False
        self.memo = {}
        return helper(s, 0, wordDict)
    
    # dynamic programming: O(N2) time, O(N) space
    def wordBreak(self, s, wordDict):
        # dp[l]: whether substr from head (length l) is word compound
        dp = [False for i in range(len(s) + 1)]   
        dp[0] = True   # base: empty string is True
        for l in xrange(1, len(s) + 1):
            for i in xrange(l):
                if dp[i] and s[i: l] in wordDict:
                    dp[l] = True
        return dp[-1]
    
    # BFS
        