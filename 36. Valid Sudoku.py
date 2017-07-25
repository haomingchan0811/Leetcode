class Solution(object):
    
    # hash table: O(1) time & space 
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        rows = [{j:0 for j in range(1, 10)} for i in range(9)]        
        cols = [{j:0 for j in range(1, 10)} for i in range(9)]          
        squares = [{j:0 for j in range(1, 10)} for i in range(9)]    
        for i in xrange(9):
            for j in xrange(9):
                n = board[i][j]
                if n != '.': 
                    n, k = int(n), i / 3 * 3 + j / 3
                    if rows[i][n] or cols[j][n] or squares[k][n]:
                        return False
                    rows[i][n] = cols[j][n] = squares[k][n] = 1
        return True
                