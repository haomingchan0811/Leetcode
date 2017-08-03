class Solution(object):
    
    # two-pass: O(N2) time, O(m+n) space
    def findLonelyPixel(self, picture):
        """
        :type picture: List[List[str]]
        :rtype: int
        """
        m, n = len(picture), len(picture[0])
        rows = [0 for i in xrange(m)]
        cols = [0 for i in xrange(n)]
        for i in xrange(m):
            for j in xrange(n):
                if picture[i][j] == 'B':
                    rows[i] += 1
                    cols[j] += 1
        ret = 0
        for i in xrange(m):
            for j in xrange(n):
                if picture[i][j] == 'B' and rows[i] == cols[j] == 1:
                    ret += 1
        return ret
        