class Solution(object):
    
#     # brute force, backtracking: (2^N) time, O(1) space, TLE
#     def removeInvalidParentheses(self, s):
#         """
#         :type s: str
#         :rtype: List[str]
#         """
#         def helper(s, i, curr, stack):  
#             if i == len(s):
#                 if len(stack) == 0:
#                     self.paren.add(curr) 
#             else:
#                 for j in xrange(i, len(s)):
#                     if s[j] not in ['(', ')']:
#                         helper(s, j + 1, curr + s[j], stack)
#                     else:
#                         if s[j] == ')' and stack and stack[-1] == '(':
#                             stack.pop()
#                             helper(s, j + 1, curr + s[j], stack)
#                             stack.append('(')
#                         else:
#                             stack.append(s[j])
#                             helper(s, j + 1, curr + s[j], stack)
#                             stack.pop()
#                 helper(s, len(s), curr, stack)  # bug: remove last one
                
#         self.paren, ret, maxLen = set([""]), [], 0
#         helper(s, 0, '', [])
#         for elem in self.paren:
#             if len(elem) > maxLen:
#                 maxLen = len(elem)
#                 ret = [elem]
#             elif len(elem) == maxLen:
#                 ret.append(elem)
#         return ret

#     # backtracking with memorization: (N2) time, O(2^N) space, better TLE
#     def removeInvalidParentheses(self, s):
#         def helper(s, i, curr, stack):  
#             if i == len(s):
#                 if len(stack) == 0:
#                     self.paren.add(curr) 
#                 self.memo.add((i, curr, len(stack)))
#             else:
#                 if (i, curr, len(stack)) not in self.memo:
#                     for j in xrange(i, len(s)):
#                         if s[j] not in ['(', ')']:
#                             helper(s, j + 1, curr + s[j], stack)
#                             self.memo.add((j + 1, curr + s[j], len(stack)))
#                         else:
#                             if s[j] == ')' and stack and stack[-1] == '(':
#                                 stack.pop()
#                                 helper(s, j + 1, curr + s[j], stack)
#                                 self.memo.add((j + 1, curr + s[j], len(stack)))
#                                 stack.append('(')
#                             else:
#                                 stack.append(s[j])
#                                 helper(s, j + 1, curr + s[j], stack)
#                                 self.memo.add((j + 1, curr + s[j], len(stack)))
#                                 stack.pop()
#                 helper(s, len(s), curr, stack)  # bug: remove last one
#                 self.memo.add((len(s), curr, len(stack)))
                
#         self.paren, self.memo = set([""]), set()
#         ret, maxLen = [], 0
#         helper(s, 0, '', [])
#         for elem in self.paren:
#             if len(elem) > maxLen:
#                 maxLen = len(elem)
#                 ret = [elem]
#             elif len(elem) == maxLen:
#                 ret.append(elem)
#         return ret

    # BFS, remove paren gradually: (N2) time, O(2^N) space
    def removeInvalidParentheses(self, s):
        def isvalid(s):   # check whether parenthess are valid
            counter = 0
            for c in s:
                if c == '(':
                    counter += 1
                elif c == ')':
                    counter -= 1
                    if counter < 0:
                        return False
            return counter == 0
        
        strings = {s}
        while True:
            valid = filter(isvalid, strings)
            if valid:
                return valid
            strings = {s[:i] + s[i+1:] for s in strings for i in range(len(s))}
        