class Solution(object):
    
    # binary search: O(NlogN) time, O(1) space
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        def validate(citations, h):
            cited = [c for c in citations if c >= h]
            return len(cited) >= h
        
        if len(citations) == 0:
            return 0
        low, high = 0, len(citations)
        while low + 1 < high:
            mid = low + (high - low) / 2
            if validate(citations, mid):
                low = mid
            else:
                high = mid
        if validate(citations, high):
            return high
        return low
            
        