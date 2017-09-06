# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    # binary search: O(logN) time, O(1) space
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        low, high = 1, n
        while low + 1 < high:
            mid = low + (high - low) / 2
            if isBadVersion(mid):
                high = mid
            else:
                low = mid
        if isBadVersion(low):
            return low
        return high
        