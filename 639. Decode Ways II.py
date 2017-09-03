class Solution(object):
    
#     # backtracking with memorization: O(N) time, O(N) space, TLE
#     def numDecodings(self, s):
#         """
#         :type s: str
#         :rtype: int
#         """
#         def helper(s, idx):
#             if idx == len(s):
#                 return 1
#             elif idx not in self.memo:
#                 temp = 0
#                 if s[idx] == '*':
#                     temp += helper(s, idx + 1) * 9
#                     if idx + 1 < len(s):
#                         if s[idx + 1] != '*':
#                             count = len([x for x in range(1, 10) if 10 <= 10 * x + int(s[idx + 1]) <= 26])
#                             temp += helper(s, idx + 2) * count
#                         else:
#                             temp += helper(s, idx + 2) * 15     # valid number for "**"
#                 elif s[idx] != '0':
#                     temp += helper(s, idx + 1)
#                     if idx + 1 < len(s):
#                         if s[idx + 1] != '*' and 0 <= int(s[idx: idx + 2]) <= 26:
#                             temp += helper(s, idx + 2)
#                         elif s[idx + 1] == '*':
#                             count = len([x for x in range(1, 10) if 10 <= x + int(s[idx]) * 10 <= 26])
#                             temp += helper(s, idx + 2) * count
#                 self.memo[idx] = temp
#             return self.memo[idx]
        
#         if len(s) == 0:
#             return 0
#         self.memo = {}
#         return helper(s, 0)


    # dynamic programming: O(N) time, O(1) space
    def numDecodings(self, s):
        if len(s) == 0 or s[0] == '0':
            return 0
        Mod = 10 ** 9 + 7
        prev2 = 1
        prev1 = 9 if s[0] == '*' else 1
        
        for i in xrange(1, len(s)):
            curr = 0 if s[i] == '0' else prev1 * (9 if s[i] == '*' else 1)  # single digit
            if s[i] == '*':
                if s[i - 1] == '*':
                    curr = (curr + prev2 * 15) % Mod
                elif s[i - 1] == '1':
                    curr = (curr + prev2 * 9) % Mod                
                elif s[i - 1] == '2':
                    curr = (curr + prev2 * 6) % Mod
            else:
                if s[i - 1] == '*':
                    curr = (curr + prev2 * (2 if s[i] <= '6' else 1)) % Mod
                elif 10 <= int(s[i - 1: i + 1]) <= 26:
                    curr = (curr + prev2) % Mod
            prev2, prev1 = prev1, curr
        return prev1  
            
        
        
        