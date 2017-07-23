# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    
    # sort: O(NlogN) time, O(1) space
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if len(intervals) == 0:
            return []
        intervals = sorted(intervals, key = lambda x: (x.start, x.end))
        start, end, ret = intervals[0].start, intervals[0].end, []
        for i in xrange(1, len(intervals)):
            if end >= intervals[i].start:
                # end = intervals[i].end   # bug!
                end = max(intervals[i].end, end)
            else:
                ret.append(Interval(start, end))
                start, end = intervals[i].start, intervals[i].end
        ret.append(Interval(start, end))
        return ret
    
    # sort, more elegant: O(NlogN) time, no space
    def merge(self, intervals):
        ret = []
        intervals = sorted(intervals, key = lambda x: x.start)
        for elem in intervals:
            if ret and elem.start <= ret[-1].end:
                ret[-1].end = max(elem.end, ret[-1].end)
            else:
                ret.append(elem)
        return ret
            
        