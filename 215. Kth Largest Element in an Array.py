import heapq

class Solution(object):
    
    # sort: O(NlogN) time, no space
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        return nums[-k]
        
    # min heap: O(NlogK) time, O(k) space
    def findKthLargest(self, nums, k):
        ret = [float('-inf')] * k
        for num in nums:
            heapq.heappushpop(ret, num)
        return ret[0]
        