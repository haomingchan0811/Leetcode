class Solution(object):
    
    # dynamic programming: O(mn) time, O(mn) space
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        if len(obstacleGrid) == 0:
            return 0
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        dp = [[0 for i in range(n)] for j in range(m)]
        for i in range(m):
            for j in range(n):
                if i == 0:
                    dp[i][j] = 0 if obstacleGrid[i][j] else (dp[i][j - 1] if j else 1)  
                elif j == 0:
                    dp[i][j] = 0 if obstacleGrid[i][j] else (dp[i - 1][j] if i else 1)
                elif obstacleGrid[i][j] != 1:
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        return dp[-1][-1]
    
    # dynamic programming: O(mn) time, O(n) space
    def uniquePathsWithObstacles(self, obstacleGrid):
        if len(obstacleGrid) == 0:
            return 0
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        dp = [0 for _ in range(n)]
        for j in range(n):
            if obstacleGrid[0][j] == 0:
                dp[j] = 1
            else:
                break
                
        for i in range(1, m):
            for j in range(n):
                if obstacleGrid[i][j] != 1:
                    dp[j] += dp[j - 1] if j else 0
                else:
                    dp[j] = 0
        return dp[-1]
        