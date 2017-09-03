class Solution(object):
    
#     # backtracking: O(2^N) time & space, TLE
#     def numDecodings(self, s):
#         """
#         :type s: str
#         :rtype: int
#         """
#         def helper(s, start):
#             if start == len(s):
#                 self.ret += 1
#                 return 
#             if s[start] != '0':    # bug: '0' has zero decode ways
#                 helper(s, start + 1)
#                 if start + 1 < len(s) and int(s[start:start + 2]) <= 26:
#                     helper(s, start + 2)
                    
#         if len(s) == 0:   
#             return 0
#         self.ret = 0
#         helper(s, 0)
#         return self.ret


    # backtracking with memorization: O(N2) time, O(N) space
    def numDecodings(self, s):
        def helper(s, idx):
            if idx == len(s):
                return 1
            elif idx not in self.memo:
                if s[idx] == '0':       
                    self.memo[idx] = 0
                else:
                    j, k = helper(s, idx + 1), 0
                    if idx + 1 < len(s) and int(s[idx: idx + 2]) <= 26:
                        k = helper(s, idx + 2)
                    self.memo[idx] = j + k
            return self.memo[idx]
            
        if len(s) == 0:   
            return 0
        self.memo = {}
        return helper(s, 0)


    # dynamic programming: O(N) time, O(1) space
    def numDecodings(self, s):
        if len(s) == 0 or s[0] == '0':   
            return 0
        
        snd2prev = 1
        prev = 0 if s[0] == '0' else 1
        for i in xrange(2, len(s) + 1):  # length
            temp = 0
            if 10 <= int(s[i - 2:i]) <= 26:
                temp += snd2prev
            if s[i - 1] != '0':
                temp += prev
            snd2prev, prev = prev, temp
        return prev