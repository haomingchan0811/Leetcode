class Solution(object):
    
#     # brute force: O(2^N)time ??? & space, TLE
#     def generateParenthesis(self, n):
#         """
#         :type n: int
#         :rtype: List[str]
#         """
#         if n == 0: return []
#         self.ret, self.n = set(), n
#         self.helper(n, n, '')
#         return list(self.ret)
    
#     def helper(self, left, right, curr):
#         if left == right == 0:
#             self.ret.add(curr)
#         else:
#             for i in xrange(1, left+1):
#                 self.helper(left-i, right, curr + '('*i)
#             for j in xrange(1, right-left+1):
#                 self.helper(left, right-j, curr + ')'*j)


    # back tracking: O(2^N)time ??? & space, TLE
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        if n == 0: return []
        self.ret, self.n = [], n
        self.helper(n, n, '')
        return self.ret
    
    def helper(self, left, right, curr):
        if left == right == 0:
            self.ret.append(curr)
        else:
            if left:
                self.helper(left-1, right, curr + '(')
            if right > left:
                self.helper(left, right-1, curr + ')')