from collections import Counter
import heapq
class Solution(object):
    
    # hash map and sort: O(NlogN) time, O(N) space
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        d = Counter(nums)
        sortedCnt = sorted(d.items(), key = lambda x: x[1], reverse = True)
        return map(lambda x: x[0], sortedCnt[:k])
        
    # hash map and heap: O(Nlogk) time, O(N) space
    def topKFrequent(self, nums, k):
        d, h, ret = Counter(nums), [float('-inf')] * k, []
        for _, cnt in d.items():
            heapq.heappushpop(h, cnt)
        for num, cnt in d.items():
            if cnt >= h[0]: ret.append(num)
        return ret
        
        