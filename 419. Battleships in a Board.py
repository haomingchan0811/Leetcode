class Solution(object):
    
    # dfs: O(mn) time, no space
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        m, n = len(board), len(board[0])
        def dfs(board, i, j):
            board[i][j] = '.'
            dirs = [(0, 1), (1, 0)]
            for d in dirs:
                x, y = i + d[0], j + d[1]
                if x < 0 or x > m - 1 or y < 0 or y > n - 1 or board[x][y] == '.':
                    continue
                else:
                    dfs(board, x, y)
        cnt = 0
        for i in xrange(m):
            for j in xrange(n):
                if board[i][j] == 'X':
                    dfs(board, i, j)
                    cnt += 1
        return cnt
    
    # check ship head: O(mn) time, no space
    def countBattleships(self, board):
        m, n = len(board), len(board[0])
        cnt = 0
        for i in xrange(m):
            for j in xrange(n):
                if board[i][j] != '.':
                    if i == j == 0 or (i == 0 and board[i][j-1] != 'X') or (j == 0 and board[i-1][j] != 'X') or (board[i][j-1] != 'X' and board[i-1][j] != 'X'):
                        cnt += 1
        return cnt
                        
        