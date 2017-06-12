class Solution(object):
    
    # Naive, two pass traversal: O(mn) time, O(1) space, 24.57%
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not len(grid):
            return 0 
        perimeter = 0
        m, n = len(grid), len(grid[0])
        for i in xrange(m): # left & right traverse
            for j in xrange(n):
                perimeter += 1 if grid[i][j] and ((not j) or (not grid[i][j-1])) else 0
            for j in xrange(n-1, -1, -1):
                perimeter += 1 if grid[i][j] and (j == n-1 or (not grid[i][j+1])) else 0
        
        for i in xrange(n): # up & down traverse
            for j in xrange(m):
                perimeter += 1 if grid[j][i] and ((not j) or (not grid[j-1][i])) else 0
            for j in xrange(m-1, -1, -1):
                perimeter += 1 if grid[j][i] and (j == m-1 or (not grid[j+1][i])) else 0
        return perimeter
        
    # Naive, one pass traversal: O(mn) time, O(1) space, 38.84%
    def islandPerimeter(self, grid):
        if not len(grid):
            return 0 
        perimeter = 0
        m, n = len(grid), len(grid[0])
        for i in xrange(m): 
            for j in xrange(n):
                if grid[i][j]:
                    perimeter += 1 if (i == 0) or (grid[i-1][j] == 0) else 0
                    perimeter += 1 if (i == m-1) or (grid[i+1][j] == 0) else 0
                    perimeter += 1 if (j == 0) or (grid[i][j-1] == 0) else 0
                    perimeter += 1 if (j == n-1) or (grid[i][j+1] == 0) else 0
        return perimeter


    # More concise, one pass traversal: O(mn) time, O(1) space, 6.65%
    def islandPerimeter(self, grid):
        if not len(grid):
            return 0 
            
        def sumAjacent(i, j):
            ret = 0
            neighbor = [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]
            for x, y in neighbor:
                if x < 0 or x == len(grid) or y < 0 or y == len(grid[0]) or grid[x][y] == 0:
                    ret += 1
            return ret
        
        perimeter = 0
        for i in xrange(len(grid)): 
            for j in xrange(len(grid[0])):
                perimeter += sumAjacent(i, j) if grid[i][j] else 0
        return perimeter
        
        