class Solution(object):
    
    # brute force: O(N2) time & space
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        ret = [[1], [1, 1]]
        for _ in xrange(numRows, 2, -1):
            temp = [1]
            for i in xrange(len(ret[-1]) - 1):
                temp.append(ret[-1][i] + ret[-1][i + 1])
            ret.append(temp + [1])
        return ret[:numRows]
        
        