class Solution(object):
    
    # backtracking: O(2^N) time, O(1) space, TLE
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        def helper(s, idx):
            if idx == len(s):
                self.ret += 1
                return 
            if s[idx] != '0':       # bug:  '10' is valid
                helper(s, idx + 1)
                if idx + 1 < len(s) and int(s[idx: idx + 2]) <= 26:
                    helper(s, idx + 2)
            
        # if '0' in s or len(s) == 0:   # bug:  '10' is valid
        if len(s) == 0:   
            return 0
        self.ret = 0
        helper(s, 0)
        return self.ret

    # backtracking with memorization: O(N2) time, O(N) space
    def numDecodings(self, s):
        def helper(s, idx):
            if idx == len(s):
                return 1
            elif idx not in self.memo:
                if s[idx] == '0':       
                    self.memo[idx] = 0
                else:
                    self.memo[idx] = helper(s, idx + 1)
                    if idx + 1 < len(s) and int(s[idx: idx + 2]) <= 26:
                        self.memo[idx] += helper(s, idx + 2)
            return self.memo[idx]
            
        if len(s) == 0:   
            return 0
        self.memo = {}
        return helper(s, 0)

    # dynamic programming: O(N) time, O(1) space
    def numDecodings(self, s):
        if len(s) == 0 or s[0] == '0':
            return 0
        prev2, prev1 = 1, 1
        for i in xrange(1, len(s)):
            curr = 0 if s[i] == '0' else prev1
            if 10 <= int(s[i - 1: i + 1]) <= 26:
                curr += prev2
            prev2, prev1 = prev1, curr
        return prev1
                
        