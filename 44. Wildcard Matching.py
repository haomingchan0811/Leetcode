class Solution(object):
    
    # backtracking with memorization: O(mn) time, O(mn) space, TLE
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        def helper(s, p, i, j):
            if i == len(s):
                self.memo[(i, j)] = j == len(p) or p[j:] == "*" * (len(p) - j)  # match empty sequence
                return self.memo[(i, j)]
            if j == len(p) and i < len(s):
                self.memo[(i, j)] = False
                return False
            
            if (i, j) in self.memo:
                return self.memo[(i, j)]
            if p[j] == '*':
                for k in xrange(i, len(s) + 1):  # not necessary
                    if helper(s, p, k, j + 1):
                        self.memo[(i, j)] = True
                        return True
                    
            self.memo[(i, j)] = False
            if p[j] == '?' or s[i] == p[j]:
                self.memo[(i, j)] = helper(s, p, i + 1, j + 1)
            return self.memo[(i, j)]
        
        self.memo = {}
        return helper(s, p, 0, 0)

    
    # dynamic programming: O(mn) time, O(mn) space
    def isMatch(self, s, p):
        m, n = len(s), len(p)
        dp = [[False for _ in range(n + 1)] for __ in range(m + 1)]
        dp[0][0] = True   # base case
        count = 0
        for j in xrange(1, n + 1):
            count += 1 if p[j - 1] == '*' else 0
            dp[0][j] = p[:j] == '*' * j   # base case  !!!
        
        if n - count > m:
            return False
        
        for i in xrange(1, m + 1):
            for j in xrange(1, n + 1):
                if p[j - 1] != '*':
                    dp[i][j] = (p[j - 1] in ['?', s[i - 1]]) and dp[i - 1][j - 1]
                else:
                    # for k in xrange(i + 1):  # not necessary
                        # dp[i][j] |= dp[k][j - 1]
                    dp[i][j] = dp[i][j - 1] or dp[i - 1][j]  # key
        return dp[m][n]
        
        


                