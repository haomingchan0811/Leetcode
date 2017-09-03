class Solution(object):
    
    # ! find maximal square in the histogram: O(N) time, O(1) space, TLE
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        if len(citations) == 0:
            return 0
        for i in xrange(len(citations), -1, -1):
            if i != 0 and citations[len(citations) - i] >= i:
                return i
        return 0 if citations[0] == 0 else 1

    
    # ! more elegant, binary search: O(logN) time, O(1) space
    def hIndex(self, citations):
        if len(citations) == 0:
            return 0
        low, high = 0, len(citations) - 1
        while low + 1 < high:
            mid = low + (high - low) / 2
            if citations[mid] >= len(citations) - mid:
                high = mid
            else:
                low = mid
        if citations[low] >= len(citations) - low:
            return len(citations) - low
        if citations[high] >= len(citations) - high:
            return len(citations) - high
        return 0
        