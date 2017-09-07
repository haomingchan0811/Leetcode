class Solution(object):
    
#     # dfs, backtracking: O(4^N) time, O(1) space
#     def exist(self, board, word):
#         """
#         :type board: List[List[str]]
#         :type word: str 
#         :rtype: bool
#         """
#         def helper(board, word, idx, i, j):
#             if idx == len(word):
#                 return True
#             dirs = [1, 0, -1, 0, 1]
#             for k in xrange(1, len(dirs)):
#                 x, y = i + dirs[k - 1], j + dirs[k]
#                 if 0 <= x < self.m and 0 <= y < self.n and (not self.visited[(x, y)]) and board[x][y] == word[idx]: 
#                     self.visited[(x, y)] = True
#                     if helper(board, word, idx + 1, x, y):   # can not go back
#                         return True
#                     self.visited[(x, y)] = False
#             return False
        
#         if word == '':
#             return True
#         self.m, self.n = len(board), len(board[0])
#         self.visited = {(i, j): False for i in range(self.m) for j in range(self.n)}
#         for i in xrange(self.m):
#             for j in xrange(self.n):
#                 if board[i][j] == word[0]:
#                     if not self.visited[(i, j)]:
#                         self.visited[(i, j)] = True
#                         if helper(board, word, 1, i, j):
#                             return True
#                         self.visited[(i, j)] = False
#         return False

    # more elegant, dfs, backtracking: O(4^N) time, O(mn) space
    def exist(self, board, word):
        
        def helper(board, word, idx, i, j):
            if idx == len(word):
                return True
            if i < 0 or i == self.m or j < 0 or j == self.n or self.visited[(i, j)] or board[i][j] != word[idx]:
                return False
            self.visited[(i, j)] = True
            flag = helper(board, word, idx + 1, i + 1, j) or helper(board, word, idx + 1, i - 1, j) \
                or helper(board, word, idx + 1, i, j + 1) or helper(board, word, idx + 1, i, j - 1)
            self.visited[(i, j)] = False
            return flag
        
        self.m, self.n = len(board), len(board[0])
        self.visited = {(i, j): False for i in range(self.m) for j in range(self.n)}
        for i in xrange(self.m):
            for j in xrange(self.n):
                if helper(board, word, 0, i, j):
                    return True
        return False

    # more elegant, dfs, backtracking: O(4^N) time, O(1) space
    def exist(self, board, word):
        
        def helper(board, word, idx, i, j):
            if idx == len(word):
                return True
            if i < 0 or i == self.m or j < 0 or j == self.n or board[i][j] != word[idx]:
                return False
            board[i][j] = '-1'
            flag = helper(board, word, idx + 1, i + 1, j) or helper(board, word, idx + 1, i - 1, j) \
                or helper(board, word, idx + 1, i, j + 1) or helper(board, word, idx + 1, i, j - 1)
            board[i][j] = word[idx]
            return flag
        
        self.m, self.n = len(board), len(board[0])
        for i in xrange(self.m):
            for j in xrange(self.n):
                if helper(board, word, 0, i, j):
                    return True
        return False
                
        
        
        