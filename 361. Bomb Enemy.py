class Solution(object):
    
#     # brute force: O(mn(m+n)) time, O(1) space, TLE
#     def maxKilledEnemies(self, grid):
#         """
#         :type grid: List[List[str]]
#         :rtype: int
#         """
#         if len(grid) == 0 or len(grid[0]) == 0:
#             return 0
#         m, n, ret = len(grid), len(grid[0]), 0   
#         def searchRow(left, right, row, step):
#             count = 0
#             for i in xrange(left, right, step):
#                 if grid[row][i] == 'W':
#                     return count
#                 if grid[row][i] == 'E':
#                     count += 1
#             return count
        
#         def searchColumn(up, down, col, step):
#             count = 0
#             for i in xrange(up, down, step):
#                 if grid[i][col] == 'W':
#                     return count
#                 if grid[i][col] == 'E':
#                     count += 1
#             return count
        
#         for i in xrange(m):
#             for j in xrange(n):
#                 if grid[i][j] == '0':
#                     cnt = searchColumn(i + 1, m, j, 1) + searchColumn(i - 1, -1, j, -1)
#                     cnt += searchRow(j + 1, n, i, 1) + searchRow(j - 1, -1, i, -1)
#                     ret = max(ret, cnt)
#         return ret

    # dynamic programming: O(mn) time, O(mn) space
    def maxKilledEnemies(self, grid):
        if len(grid) == 0 or len(grid[0]) == 0:
            return 0
        m, n, ret = len(grid), len(grid[0]), 0   
        [up, down, left, right] = [[[0 for j in range(n)] for i in range(m)] for k in range(4)]

        # upperleft to lowerright
        for i in xrange(m):
            for j in xrange(n):
                if grid[i][j] != 'W':
                    right[i][j] = int(grid[i][j] == 'E') + (right[i][j - 1] if j != 0 else 0)
                    down[i][j] = int(grid[i][j] == 'E') + (down[i - 1][j] if i != 0 else 0)
                    
        # lowerright to upperleft
        for i in xrange(m - 1, -1, -1):
            for j in xrange(n - 1, -1, -1):
                if grid[i][j] != 'W':
                    up[i][j] = int(grid[i][j] == 'E') + (up[i + 1][j] if i != m - 1 else 0)
                    left[i][j] = int(grid[i][j] == 'E') + (left[i][j + 1] if j != n - 1 else 0)
        
        for i in xrange(m):
            for j in xrange(n):
                if grid[i][j] == '0':
                    ret = max(ret, up[i][j] + down[i][j] + left[i][j] + right[i][j])
        return ret

    # better dynamic programming: O(mn) time, O(mn) space
    def maxKilledEnemies(self, grid):
        if len(grid) == 0 or len(grid[0]) == 0:
            return 0
        m, n, ret = len(grid), len(grid[0]), 0   
        [up, down, left, right] = [[[0 for j in range(n)] for i in range(m)] for k in range(4)]

        # upperleft to lowerright
        for i in xrange(m):
            for j in xrange(n):
                if grid[i][j] != 'W':
                    right[i][j] = int(grid[i][j] == 'E') + (right[i][j - 1] if j != 0 else 0)
                    down[i][j] = int(grid[i][j] == 'E') + (down[i - 1][j] if i != 0 else 0)
                    
        # lowerright to upperleft
        for i in xrange(m - 1, -1, -1):
            for j in xrange(n - 1, -1, -1):
                if grid[i][j] != 'W':
                    up[i][j] = int(grid[i][j] == 'E') + (up[i + 1][j] if i != m - 1 else 0)
                    left[i][j] = int(grid[i][j] == 'E') + (left[i][j + 1] if j != n - 1 else 0)
                if grid[i][j] == '0':  # move final check here 
                    ret = max(ret, up[i][j] + down[i][j] + left[i][j] + right[i][j])
        return ret
                    
        