class Solution(object):
    
    # dp: O(mn) time, no space
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if len(grid) == 0 or len(grid[0]) == 0: 
            return 0
        m, n = len(grid), len(grid[0])
        for i in xrange(1, m):
            grid[i][0] += grid[i-1][0]
        for j in xrange(1, n):
            grid[0][j] += grid[0][j-1]
        for i in xrange(1, m):
            for j in xrange(1, n):
                grid[i][j] += min(grid[i-1][j], grid[i][j-1])
        return grid[m-1][n-1]
        