class Solution(object):
    
    # dynamic programming: O(mn) time & space
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        m, n = len(word1) + 1, len(word2) + 1
        # dist = [[0] * m] * n   # WRONG WAY TO INIT: REFERENCE!!!!
        dist = [range(m) for i in range(n)]
        for i in xrange(n): dist[i][0] = i  
            
        for i in xrange(1, n):
            for j in xrange(1, m):
                if word1[j-1] == word2[i-1]:
                    dist[i][j] = dist[i-1][j-1]
                else:
                    dist[i][j] = min(dist[i-1][j], dist[i][j-1], dist[i-1][j-1]) + 1
        return dist[-1][-1]

    # !! dynamic programming: O(mn) time, O(m) space
    def minDistance(self, word1, word2):
        m, n = len(word1) + 1, len(word2) + 1
        dist = range(m) 
            
        for i in xrange(1, n):
            prev = i
            for j in xrange(1, m):
                curr = None
                if word1[j-1] == word2[i-1]:
                    curr = dist[j-1]
                else:
                    curr = min(dist[j], dist[j-1], prev) + 1
                dist[j-1] = prev
                prev = curr
            dist[-1] = prev
        return dist[-1]
        