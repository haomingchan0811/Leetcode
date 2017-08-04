# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    
    # heap, priority_queue: O(NlogN) time, O(N) space
    def minMeetingRooms(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        intervals = sorted(intervals, key = lambda x: x.start)
        heap = []
        for elem in intervals:
            if len(heap) == 0 or heap[0] > elem.start:
                heapq.heappush(heap, elem.end)
            else:
                heapq.heappushpop(heap, elem.end)
        return len(heap)
    
    # !! sort and hashmap: O(NlogN) time, O(N) space
    def minMeetingRooms(self, intervals):
        change, times = {}, []
        ret, rooms = 0, 0
        for elem in intervals:
            change[elem.start] = change.get(elem.start, 0) + 1
            change[elem.end] = change.get(elem.end, 0) - 1
            heapq.heappush(times, elem.start)
            heapq.heappush(times, elem.end)
        
        prev = None
        while times:
            while prev and times and prev == times[0]:  # bug: check times is not empty
                heapq.heappop(times)
            if times:
                prev = heapq.heappop(times)
                rooms += change[prev]
                ret = max(ret, rooms)
        return ret