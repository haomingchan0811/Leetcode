class Solution(object):
    
    # binary search: O(logN) time, O(1) space
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x < 0:
            return -1
        low, high = 0, x
        while low <= high:
            mid = low + (high - low) / 2
            curr = mid ** 2
            if curr <= x and (mid + 1) ** 2 > x:
                return mid
            elif curr < x:
                low = mid + 1
            else:
                high = mid - 1
        return -1
            