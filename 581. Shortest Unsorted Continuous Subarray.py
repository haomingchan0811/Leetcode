class Solution(object):
    
    # brute force: O(N3) time, O(N) space, TLE
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def isAscend(sub):
            for i in xrange(len(sub)):
                if i != 0 and sub[i] < sub[i - 1]:
                    return False
            return True
        
        if isAscend(nums):
            return 0
        for length in xrange(2, len(nums) + 1):
            for start in xrange(len(nums) - length + 1):
                end = start + length
                sub = nums[start:end]
                sub.sort()
                if isAscend(nums[:start] + sub + nums[end:]):
                    return length
    
    # ! sort and two pass: O(NlogN) time, O(N) space
    def findUnsortedSubarray(self, nums):
        sorted_nums = list(nums)
        sorted_nums.sort()
        start = None
        for i in xrange(len(nums)):
            if nums[i] != sorted_nums[i]:
                start = i - 1
                break
        if start is None:
            return 0
        for j in xrange(len(nums) - 1, -1, -1):
            if nums[j] != sorted_nums[j]:
                return j - start
    
    # !! stack: O(N) time, O(N) space
    def findUnsortedSubarray(self, nums):
        stack = []
        left, right = len(nums), 0
        for i in xrange(len(nums)):
            while stack and nums[stack[-1]] > nums[i]:
                left = min(left, stack.pop())
            stack.append(i)
        stack = []
        for j in xrange(len(nums) - 1, -1, -1):
            while stack and nums[stack[-1]] < nums[j]:
                right = max(right, stack.pop())
            stack.append(j)
        return right - left + 1 if left < right else 0