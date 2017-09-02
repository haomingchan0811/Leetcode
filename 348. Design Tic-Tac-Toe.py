class TicTacToe(object):

    # hash table: O(4) time, O(n) space 
    def __init__(self, n):
        """
        Initialize your data structure here.
        :type n: int
        """
        self.n = n
        self.rows = [[0 for _ in range(n)] for k in range(2)]
        self.cols = [[0 for _ in range(n)] for k in range(2)]
        self.leftDiag = [0, 0]
        self.rightDiag = [0, 0]

    def move(self, row, col, player):
        """
        Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins.
        :type row: int
        :type col: int
        :type player: int
        :rtype: int
        """
        self.rows[player - 1][row] += 1
        self.cols[player - 1][col] += 1
        if row == col:
            self.rightDiag[player - 1] += 1
        if row + col == self.n - 1:
            self.leftDiag[player - 1] += 1
        if self.n in [self.rows[player - 1][row], self.cols[player - 1][col], self.rightDiag[player - 1], self.leftDiag[player - 1]]:
            return player
        return 0 


# Your TicTacToe object will be instantiated and called as such:
# obj = TicTacToe(n)
# param_1 = obj.move(row,col,player)