class Solution(object):
    
    # # BFS: O(mn*k) time, O(mn) space (k is the number of gates), TLE
    # def wallsAndGates(self, rooms):
    #     """
    #     :type rooms: List[List[int]]
    #     :rtype: void Do not return anything, modify rooms in-place instead.
    #     """
    #     if len(rooms) == 0 or len(rooms[0]) == 0:
    #         return 
    #     m, n = len(rooms), len(rooms[0])
    #     dirs = [1, 0, -1, 0, 1]
    #     for i in xrange(m):
    #         for j in xrange(n):
    #             if rooms[i][j] == 0:
    #                 queue = [(i, j, 0)]
    #                 visited = [[0 for col in range(n)] for row in range(m)]
    #                 for (x, y, dist) in queue:
    #                     if not (x < 0 or x == m or y < 0 or y == n or rooms[x][y] == -1 or visited[x][y]):
    #                         visited[x][y] = 1
    #                         temp = min(rooms[x][y], dist)
    #                         if temp < rooms[x][y] or temp == 0:    # optimize: early stop
    #                             rooms[x][y] = temp
    #                             for k in range(1, len(dirs)):
    #                                 queue.append((x + dirs[k - 1], y + dirs[k], dist + 1))
    
    # !! BFS, update neighbor simultaneously: O(mn) time, O(mn) space 
    def wallsAndGates(self, rooms):
        if len(rooms) == 0 or len(rooms[0]) == 0:
            return 
        m, n = len(rooms), len(rooms[0])
        dirs = [1, 0, -1, 0, 1]
        queue = []
        
        for i in xrange(m):
            for j in xrange(n):
                if rooms[i][j] == 0:
                    queue.append((i, j))
        for (x, y) in queue:
            for k in range(1, len(dirs)):
                xk, yk = x + dirs[k - 1], y + dirs[k]
                if 0 <= xk < m and 0 <= yk < n and rooms[xk][yk] == 2147483647:
                    rooms[xk][yk] = rooms[x][y] + 1
                    queue.append((xk, yk))

            