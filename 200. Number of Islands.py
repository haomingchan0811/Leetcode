class Solution(object):
    
    # dfs with flag: O(mn)time & space
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        cnt, visited = 0, [[0 for j in xrange(len(grid[0]))] for i in xrange(len(grid))]
        def dfs(i, j):
            if 0 <= i < len(grid) and 0 <= j < len(grid[0]) and not visited[i][j] and grid[i][j] == '1':
                visited[i][j] = 1
                dir = [1, 0, -1, 0, 1]
                map(dfs, map(lambda x: x+i, dir[:-1]), map(lambda x: x+j, dir[1:]))
            return None
            
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                if not visited[i][j] and grid[i][j] == '1':
                    dfs(i, j)
                    cnt += 1
        return cnt

    # dfs: O(mn) time, O(1) space
    def numIslands(self, grid):
        cnt = 0
        def dfs(i, j):
            if 0 <= i < len(grid) and 0 <= j < len(grid[0]) and grid[i][j] == '1':
                grid[i][j] = '0'
                dir = [1, 0, -1, 0, 1]
                map(dfs, map(lambda x: x+i, dir[:-1]), map(lambda x: x+j, dir[1:]))
            return None
            
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                if grid[i][j] == '1':
                    dfs(i, j)
                    cnt += 1
        return cnt  
    
    # union find: O(MN) time, O(1) space
    