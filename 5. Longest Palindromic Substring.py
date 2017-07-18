class Solution(object):
    
#     # brute force: O(N3) time, O(N) space, TLE
#     def longestPalindrome(self, s):
#         """
#         :type s: str
#         :rtype: str
#         """
#         def isPalindrome(string):
#             i, j = 0, len(string) - 1
#             while i < j:
#                 if string[i] != string[j]:
#                     return False
#                 i, j = i + 1, j - 1
#             return True
        
#         if len(s) < 2: 
#             return s
#         ret = ''
#         for i in xrange(len(s)):
#             for j in xrange(i + 1, len(s) + 1):
#                 if isPalindrome(s[i:j]) and len(ret) < j - i:
#                     ret = s[i:j]
#         return ret

#     # Expand Around Center: O(N2) time, O(N) space (can be O(1) if saving index instead of string)
#     def longestPalindrome(self, s):
#         if len(s) < 2: 
#             return s
#         ret = s[0]
#         # if palindrome is odd length
#         for i in xrange(1, len(s) - 1):
#             j = 1     
#             while i + j < len(s) and i - j >= 0:
#                 if s[i - j] != s[i + j]:
#                     if len(ret) < 2 * j - 1:
#                         ret = s[i - j + 1:i + j]
#                     break
#                 j += 1
#             # bug: forget to include whole qualified string
#             if (i + j >= len(s) or i - j < 0) and len(ret) < 2 * j - 1:  
#                 ret = s[i - j + 1:i + j]
                
#         # if palindrome is even length
#         for i in xrange(1, 2 * len(s) - 2):
#             i, j = i * 0.5, 0.5     
#             while i + j < len(s) and i - j >= 0:
#                 if s[int(i - j)] != s[int(i + j)]:
#                     if len(ret) < 2 * j - 1:
#                         ret = s[int(i - j + 1):int(i + j)]
#                     break
#                 j += 1
#             if (i + j >= len(s) or i - j < 0) and len(ret) < 2 * j - 1:  
#                 ret = s[int(i - j + 1):int(i + j)]
#         return ret

    # ! Expand Around Center, MORE ELEGANT: O(N2) time, O(1) space
    def longestPalindrome(self, s):
        def expandAroundCenter(string, left, right):
            while left >= 0 and right < len(string) and string[left] == string[right]:
                left, right = left - 1, right + 1
            return right - left - 1
        
        start, end = 0, 0
        for i in xrange(len(s)):
            len1 = expandAroundCenter(s, i, i)
            len2 = expandAroundCenter(s, i, i + 1)
            currLen = max(len1, len2)
            if currLen > end - start + 1: 
                start = i - (currLen - 1) / 2
                end = i + currLen / 2
        return s[start:end + 1]

    # !! Dynamic Programming: O(N2) time & space
    def longestPalindrome(self, s):
        flag = [[0 for i in range(len(s))] for j in range(len(s))]
        ret = ''
        for k in xrange(1, len(s) + 1):  # how long the substring is 
            for i in xrange(len(s) - k + 1):
                # P(i,j) = (P(i+1,j-1) && Si==Sj)
                j = k + i - 1
                if i == j: 
                    flag[i][i] = 1                # base case1: individual char
                elif i + 1 == j: 
                    flag[i][i + 1] = int(s[i] == s[i + 1])   # base case2: length=2 char
                else:
                    flag[i][j] = flag[i + 1][j - 1] & (s[i] == s[j])
                if flag[i][j] and len(ret) < j - i + 1:
                    ret = s[i:j + 1]
        return ret
        
        