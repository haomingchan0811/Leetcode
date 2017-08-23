import bisect
class Solution(object):
    
    # brute force: O(N3) time, O(1) space, TLE
    def triangleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 3:
            return 0
        ret = 0
        for i in xrange(len(nums)):
            for j in xrange(i + 1, len(nums)):
                for k in xrange(j + 1, len(nums)):
                    a, b, c = nums[i], nums[j], nums[k]
                    if a+b>c and a+c>b and b+c>a:
                        ret += 1
        return ret
    
    # better brute force, sort: O(N3) time, O(N) space, TLE
    def triangleNumber(self, nums):
        if len(nums) < 3:
            return 0
        ret = 0
        nums.sort()
        for i in xrange(len(nums)):
            for j in xrange(i + 1, len(nums)):
                k, a, b = j + 1, nums[i], nums[j]
                while k < len(nums) and a + b > nums[k]: # sorted, only check a + b > c as a<=b<=c
                    ret, k = ret + 1, k + 1
        return ret
    
    # !! binary search: O(N2logN) time, O(logN) space, TLE
    def triangleNumber(self, nums):
        if len(nums) < 3:
            return 0
        ret = 0
        nums.sort()
        for i in xrange(len(nums)):
            for j in xrange(i + 1, len(nums)):
                # lower bound: c >= a+b for c in nums[k:]
                k = bisect.bisect_left(nums, nums[i] + nums[j], lo = j + 1) 
                ret += k - (j + 1)
        return ret
        