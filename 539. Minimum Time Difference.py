class Solution(object):
    
    # brute force: O(N2) time, O(N) space, TLE for last case
    def findMinDifference1(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        timePoints = map(lambda x: int(x[:2]) * 60 + int(x[3:]), timePoints)
        ret = float('inf')
        for i in xrange(len(timePoints)):
            for j in xrange(i+1, len(timePoints)):
                diff = abs(timePoints[i] - timePoints[j])
                ret = min(ret, min(diff, 24 * 60 - diff))
        return ret
        
    # sort: O(NlogN) time, O(N) space
    def findMinDifference(self, timePoints):
        timePoints = map(lambda x: int(x[:2]) * 60 + int(x[3:]), timePoints)
        timePoints.sort()
        ret = float('inf')
        for i in xrange(len(timePoints) - 1):
            ret = min(ret, timePoints[i+1] - timePoints[i])
        # diff = abs(timePoints[-1] - timePoints[0])
        # return min(ret, min(diff, 24 * 60 -diff))
        return min(ret, (timePoints[0] - timePoints[-1]) % (24 * 60)) # more elegant
        
                