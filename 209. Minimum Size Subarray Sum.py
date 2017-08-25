import bisect
class Solution(object):
    
    # # range sum: O(N2) time, O(1) space, TLE
    # def minSubArrayLen(self, s, nums):
    #     """
    #     :type s: int
    #     :type nums: List[int]
    #     :rtype: int
    #     """
    #     if len(nums) == 0:
    #         return 0
    #     ret = float('inf') if nums[0] < s else 1
    #     for end in xrange(len(nums)):
    #         nums[end] += nums[end - 1] if end != 0 else 0   # range sum
    #         if nums[end] >= s:
    #             ret = min(ret, end + 1)
    #         for start in xrange(end - 1, -1, -1):
    #             if nums[end] - nums[start] >= s:
    #                 ret = min(ret, end - start)
    #                 break
    #     return 0 if ret == float('inf') else ret
    
    # !!! binary search: find index j where sums[i~j] >= s, O(NlogN) time, O(N) space
    def minSubArrayLen(self, s, nums):
        if len(nums) == 0:
            return 0
        if nums[0] >= s:
            return 1
        
        ret = float('inf')
        for i in xrange(1, len(nums)):  # range sum
            nums[i] += nums[i - 1]
            if nums[i] >= s:
                ret = min(ret, i + 1)
                
        for i in xrange(len(nums)):
            target = s + nums[i]
            bound = bisect.bisect_left(nums, target)  # lower bound
            if bound != len(nums):
                ret = min(ret, bound - i)
    
        if ret == float('inf'):
            return len(nums) if nums[-1] >= s else 0
        return ret
    
    # two pointers: O(N) time, O(1) space
    def minSubArrayLen(self, s, nums):
        ret, i, j, sums = float('inf'), 0, 0, 0
        while j < len(nums):
            sums += nums[j]
            if sums >= s:
                while i <= j and sums - nums[i] >= s:
                    sums -= nums[i]
                    i += 1
                ret = min(ret, j - i + 1)
                sums -= nums[i]
                i, j = i + 1, j + 1
            else:
                j += 1
        return 0 if ret == float('inf') else ret
    
    # ! better two pointers: O(N) time, O(1) space
    def minSubArrayLen(self, s, nums):
        ret, i, j, sums = float('inf'), 0, 0, 0
        for j in xrange(len(nums)):
            sums += nums[j]
            while sums >= s:
                ret = min(ret, j - i + 1)
                sums -= nums[i]
                i += 1
        return 0 if ret == float('inf') else ret
    
        