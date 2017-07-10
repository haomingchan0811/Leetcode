class Solution(object):
    
    # brute force: O(N) time & space
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1: return s   # corner case
        row, step = 0, -1
        ret = ['' for i in xrange(numRows)]
        for c in s:
            ret[row] += c   
            if row == numRows-1 or row == 0:
                step = -step 
            row += step
        return ''.join(ret)
            