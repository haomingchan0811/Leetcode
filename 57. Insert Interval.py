# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    
    # brute force: O(N) time, O(1) space
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        print '-------'
        if len(intervals) == 0:
            return [newInterval]
        start, end, n = -1, -1, len(intervals)
        for i, inter in enumerate(intervals):
            if inter.start > newInterval.start:
                break
            start = end = i
            
        # bug: check boundry, tail corner case
        if newInterval.start > intervals[start].end:
            if end == n - 1 or newInterval.end < intervals[end + 1].start: 
                return intervals[:start + 1] + [newInterval] + intervals[end + 1:]
            else:
                start, end = start + 1, end + 1
            
        for j, inter in enumerate(intervals[start + 1:], start + 1):
            if newInterval.end < inter.start:
                break
            end = j
        
        s = min(intervals[start].start if start != -1 else newInterval.start, newInterval.start)
        e = max(intervals[end].end if end != -1 else newInterval.end, newInterval.end)
        # bug: when start == -1: intervals[:start] means all elems but the last one (python syntax)
        return ([] if start < 0 else intervals[:start]) + [Interval(s, e)] + intervals[end + 1:]

    # !! more elegant: O(N) time, O(1) space
    def insert(self, intervals, newInterval):
        s, e = newInterval.start, newInterval.end
        left = [x for x in intervals if x.end < s]
        right = [x for x in intervals if x.start > e]
        if len(left) + len(right) != len(intervals):
            s = min(s, intervals[len(left)].start)
            e = max(e, intervals[-len(right) - 1].end)  
        return left + [Interval(s, e)] + right
        
            
            
        