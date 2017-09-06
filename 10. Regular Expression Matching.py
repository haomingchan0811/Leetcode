class Solution(object):
    
    # # backtracking: O(2^mn) time, O(1) space, TLE
    # def isMatch(self, s, p):
    #     """
    #     :type s: str
    #     :type p: str
    #     :rtype: bool
    #     """
    #     def helper(s, p, i, j):
    #         if i == len(s) and j == len(p):
    #             return True
    #         if j == len(p) and i < len(s):
    #             return False
    #         if j < len(p) and i < len(s) and (s[i] == p[j] or p[j] == '.') and helper(s, p, i + 1, j + 1):
    #             return True
    #         if j + 1 < len(p) and p[j + 1] == '*':
    #             if helper(s, p, i, j + 2):   # match zero preceding element
    #                 return True
    #             while i < len(s) and p[j] in ['.', s[i]]:
    #                 if helper(s, p, i + 1, j + 2):
    #                     return True
    #                 i += 1
    #         return False
    #     return helper(s, p, 0, 0)
                
    # backtracking with memorization: O(mn^2) time, O(mn) space
    def isMatch(self, s, p):
        def helper(s, p, i, j):
            if j == len(p):
                self.memo[(i, j)] = True if i == len(s) else False
                return self.memo[(i, j)]
            if j < len(p) and i < len(s) and (s[i] == p[j] or p[j] == '.'):
                if (i + 1, j + 1) in self.memo:
                    self.memo[(i, j)] = self.memo[(i + 1, j + 1)]
                else:
                    self.memo[(i, j)] = helper(s, p, i + 1, j + 1)
                if self.memo[(i, j)]:
                    return True
                
            if j + 1 < len(p) and p[j + 1] == '*':
                if (i, j + 2) in self.memo:
                    self.memo[(i, j)] = self.memo[(i, j + 2)]
                else:
                    self.memo[(i, j)] = helper(s, p, i, j + 2)  # match zero preceding element
                if self.memo[(i, j)]:   
                    return True
                
                while i < len(s) and p[j] in ['.', s[i]]:
                    if (i + 1, j + 2) in self.memo:
                        self.memo[(i, j)] = self.memo[(i + 1, j + 2)]
                    else:
                        self.memo[(i, j)] = helper(s, p, i + 1, j + 2)  # match one or more preceding element
                    if self.memo[(i, j)]:   
                        return True
                    i += 1
            self.memo[(i, j)] = False
            return self.memo[(i, j)]
        
        self.memo = {}
        return helper(s, p, 0, 0)

    # !! dynamic programming: O(mn) time, O(mn) space
    def isMatch(self, s, p):
        dp = [[False for i in range(len(p) + 1)] for j in range(len(s) + 1)]
        dp[0][0] = True  # base case
        for j in xrange(1, len(p) + 1):
            dp[0][j] = j > 1 and p[j - 1] == '*' and dp[0][j - 2] == True  # base case
            
        for i in xrange(1, len(s) + 1):
            for j in xrange(1, len(p) + 1):
                if p[j - 1] != '*':
                    dp[i][j] = dp[i - 1][j - 1] and p[j - 1] in [s[i - 1], '.']
                else:
                    dp[i][j] = dp[i][j - 2] or (p[j - 2] in [s[i - 1], '.'] and dp[i - 1][j])
        return dp[len(s)][len(p)]
        
        