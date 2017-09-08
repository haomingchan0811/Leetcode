import heapq
class Solution(object):
    
    # # sort: O(NlogN) time, O(1) space
    # def longestConsecutive(self, nums):
    #     """
    #     :type nums: List[int]
    #     :rtype: int
    #     """
    #     if nums == []: 
    #         return 0
    #     ret, cnt = 0, 1
    #     nums.sort()
    #     for i in xrange(1, len(nums)):
    #         if nums[i] == nums[i - 1]:
    #             continue
    #         elif nums[i] == nums[i - 1] + 1:
    #             cnt += 1
    #         else:
    #             ret = max(ret, cnt)
    #             cnt = 1
    #     return max(ret, cnt)
    
    # # heap: O(NlogN) time, O(1) space
    # def longestConsecutive(self, nums):
    #     if nums == []: return 0
    #     h = []
    #     for num in nums:
    #         heapq.heappush(h, num)
    #     ret, cnt, prev = 0, 1, None
    #     while h:
    #         curr = heapq.heappop(h)
    #         if prev is not None and curr == prev + 1:
    #             cnt += 1
    #         elif prev is not None and curr == prev:
    #             continue
    #         else:
    #             ret = max(ret, cnt)
    #             cnt = 1
    #         prev = curr
    #     return max(ret, cnt)
    
        # hashmap: O(N) time
    def longestConsecutive(self, nums):
        length, ret = {}, 0
        for num in nums:
            if num not in length:
                left = length.get(num - 1, 0)
                right = length.get(num + 1, 0)
                total = left + right + 1
                length[num] = length[num - left] = length[num + right] = total
                ret = max(ret, total)
        return ret
       
        
        
        