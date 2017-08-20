class Solution(object):
    
#     # dfs with flag: O(n2) time & space     
#     def findCircleNum(self, M):
#         """
#         :type M: List[List[int]]
#         :rtype: int
#         """
#         def dfs(M, N, x, y):
#             if self.flags[x][y] or M[x][y] == 0:
#                 return 
#             self.flags[x][y] = self.flags[y][x] = True
#             for k in xrange(N):
#                 dfs(M, N, y, k)
        
#         N, ret = len(M), 0
#         self.flags = [[False for i in range(N)] for j in range(N)]
#         for i in xrange(N):
#             newCircle = False
#             for j in xrange(N):
#                 if M[i][j] and not self.flags[i][j]:
#                     newCircle = True
#                     dfs(M, N, i, j)
#             if newCircle:
#                 ret += 1
#         return ret
                    
    # ! Union Find: O(n2) time, O(N) space     
    def findCircleNum(self, M):
            
        def find(x):
            if self.root[x] == x:
                return x
            self.root[x] = find(self.root[x])
            return self.root[x]

        ret = len(M)
        self.root = range(len(M))   # init: every node's root is himself
        for i in xrange(len(M)):
            for j in xrange(len(M)):
                if M[i][j] and i != j:
                    root_i = find(i)
                    root_j = find(j)
                    if root_i != root_j:
                        self.root[root_i] = root_j    # union(i, j)
                        ret -= 1
        return ret
                    
        