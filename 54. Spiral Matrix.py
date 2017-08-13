class Solution(object):
    
    # brute force: O(N) time, O(1) space
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return []
        ret, m, n = [matrix[0][0]], len(matrix) - 1, len(matrix[0]) - 1
        x, y = 0, 0
        while m >= 0 or n >= 0:
            for i in xrange(n):
                y += 1
                ret.append(matrix[x][y])
            n = n if x == 0 else n - 1
            if m <= 0:
                break
            for i in xrange(m):
                x += 1
                ret.append(matrix[x][y])
            m -= 1
            if n <= 0:
                break
            for i in xrange(n):
                y -= 1
                ret.append(matrix[x][y])
            n -= 1
            if m <= 0:
                break
            for i in xrange(m):
                x -= 1
                ret.append(matrix[x][y])
            m -= 1
            if n <= 0:
                break
        return ret
            
                
    