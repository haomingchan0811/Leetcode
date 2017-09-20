import heapq
class Solution(object):
    
    # heap, O(Nlogk) time, O(k) space
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if len(nums) < k or k == 0:
            return []
        heap, ret = [], []
        for i in xrange(k):
            heapq.heappush(heap, (-nums[i], i))
        ret.append(-heap[0][0])
        
        for i in xrange(k, len(nums)):
            heapq.heappush(heap, (-nums[i], i))
            while heap[0][1] <= i - k:
                heapq.heappop(heap)
            ret.append(-heap[0][0])
        return ret
            
        
        