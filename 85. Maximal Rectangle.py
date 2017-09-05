class Solution(object):
    
    # ! stack: O(n2) time, O(n) space
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        def largestRecInHistogram(heights):
            stack, ret = [-1], 0
            for i in xrange(len(heights)):
                while stack[-1] != -1 and heights[i] <= heights[stack[-1]]:
                    h = heights[stack.pop()]
                    ret = max(ret, h * (i - stack[-1] - 1))  # key
                stack.append(i)
            while stack[-1] != -1:
                h = heights[stack.pop()]
                ret = max(ret, h * (len(heights) - stack[-1] - 1))  # key
            return ret
        
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return 0
        ret, n, m = 0, len(matrix), len(matrix[0]) 
        heights = [0 for i in xrange(m)]
        for i in xrange(n):
            for j in xrange(m):
                if matrix[i][j] == '0':
                    heights[j] = 0
                else:
                    heights[j] += 1
            ret = max(ret, largestRecInHistogram(heights))
        return ret
                     
        