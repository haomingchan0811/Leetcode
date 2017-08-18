class Solution(object):
    
    # brute force: O(N) time, O(1) space
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        dirs = {'U': [0, 1], 'D': [0, -1], 'L': [-1, 0], 'R': [1, 0]}
        pos = [0, 0]
        for move in moves:
            pos = map(lambda (x, y): x + y, zip(pos, dirs[move]))
        return True if pos == [0, 0] else False
    
    # check operations match: O(N) time, O(1) space
    def judgeCircle(self, moves):
        return moves.count('L') == moves.count('R') and moves.count('U') == moves.count('D')
        