class Solution(object):
    
    # # !! dynamic programming: dp[i][j] = length of maximal square ending in (i, j)
    # # O(mn) time, O(mn) space
    # def maximalSquare(self, matrix):
    #     """
    #     :type matrix: List[List[str]]
    #     :rtype: int
    #     """
    #     if len(matrix) == 0 or len(matrix[0]) == 0:
    #         return 0
    #     m, n = len(matrix), len(matrix[0])
    #     dp = [[0 for _ in range(n)] for i in range(m)]
    #     dp[0] = map(lambda x: int(x), matrix[0])   # base case
    #     ret = int(dp[0].count(1) > 0)          # bug: init by whether there's at least 1 '1'
    #     for i in xrange(1, m):
    #         for j in xrange(n):
    #             if j == 0:    # base case
    #                 dp[i][j] = int(matrix[i][j])
    #                 ret = max(ret, dp[i][j])    # bug: forget to update 
    #             elif matrix[i][j] == '1':
    #                 dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1
    #                 ret = max(ret, dp[i][j])
    #     return ret ** 2
    
    # !! more elegant, dynamic programming: dp[i][j] = length of maximal square ending in (i, j)
    # O(mn) time, O(mn) space
    def maximalSquare(self, matrix):
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return 0
        m, n, ret = len(matrix), len(matrix[0]), 0
        dp = [[0 for _ in range(n + 1)] for __ in range(m + 1)]  # add one more col and row for more elegant operation
        for i in xrange(1, m + 1):        
            for j in xrange(1, n + 1):
                if matrix[i - 1][j - 1] == '1':
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1
                    ret = max(ret, dp[i][j])
        return ret ** 2
    
    
    # !! dynamic programming: O(mn) time, O(n) space
    def maximalSquare(self, matrix):
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return 0
        m, n, ret = len(matrix), len(matrix[0]), 0
        dp = [0 for _ in range(n + 1)]  # add one more col and row for more elegant operation
        for i in xrange(1, m + 1): 
            prev = 0
            for j in xrange(1, n + 1):
                temp = dp[j]    # bug: store the previous value here
                if matrix[i - 1][j - 1] == '1':
                    dp[j] = min(dp[j], dp[j - 1], prev) + 1
                    ret = max(ret, dp[j])
                else:
                    dp[j] = 0   # bug: diffent init 
                prev = temp
        return ret ** 2
    
    
    # !! dynamic programming: O(mn) time, no space (use original matrix)
    def maximalSquare(self, matrix):
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return 0
        m, n, ret = len(matrix), len(matrix[0]), 0
        for i in xrange(m): 
            for j in xrange(n):
                if i == 0 or j == 0 or matrix[i][j] == '0':
                    matrix[i][j] = int(matrix[i][j])
                else:
                    matrix[i][j] = min(matrix[i - 1][j], matrix[i - 1][j - 1], matrix[i][j - 1]) + 1
                ret = max(ret, matrix[i][j])
        return ret ** 2
        