import heapq
class Solution(object):
    
    # sort: O(NlogN) time, no space
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        ret = 0
        for i in xrange(len(nums) / 2):
            ret += nums[i * 2]
        return ret
    
    # sort, pythonic: O(NlogN) time, O(N) space
    def arrayPairSum(self, nums):
        nums.sort()
        return reduce(lambda x, y: x + y, [nums[i * 2] for i in range(len(nums) / 2)])
    
    # heap: O(NlogN) time, O(N) space
    def arrayPairSum(self, nums):
        h, ret = [], 0
        for n in nums:
            heapq.heappush(h, n)
        for i in range(len(nums) / 2):
            ret += heapq.heappop(h)
            heapq.heappop(h)
        return ret
    
    # heap: O(NlogN) time, O(N) space
    def arrayPairSum(self, nums):
        h, ret = [], 0
        for n in nums:
            heapq.heappush(h, n)
        for i in range(len(nums) / 2):
            ret += heapq.heappop(h)
            heapq.heappop(h)
        return ret
    
    # ! hashtable: O(NlogN) time, O(N) space
    def arrayPairSum(self, nums):
        arr = [0 for i in range(200001)]
        for n in nums:
            arr[n + 10000] += 1
        ret, remain = 0, 0
        for i in xrange(-10000, 10001):
            ret += (arr[i + 10000] + 1 - remain) / 2 * i
            remain = (arr[i + 10000] + remain) % 2
        return ret
        