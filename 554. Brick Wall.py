class Solution(object):
    
    # rangeSum, hashtable: O(n) time (n = # bricks), O(m) space
    def leastBricks(self, wall):
        """
        :type wall: List[List[int]]
        :rtype: int
        """
        if len(wall) == 0 or len(wall[0]) == 0:
            return 0
        count = {}
        for row in wall:
            length = 0
            for i in xrange(len(row) - 1):
                length += row[i]
                count[length] = count.get(length, 0) + 1
        ret = len(wall)     # bug: corner case -> each row has exactly one elem
        for _, cnt in count.items():
            ret = min(ret, len(wall) - cnt)
        return ret  
        