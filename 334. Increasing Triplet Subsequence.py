class Solution(object):
    
    # brute force: O(N3) time, O(1) space, TLE
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) < 3:
            return False
        for i in xrange(len(nums)):
            for j in xrange(i + 1, len(nums)):
                for k in xrange(j + 1, len(nums)):
                    if nums[i] < nums[j] < nums[k]:
                        return True
        return False
    
    # stack: O(N2) time, O(1) space, TLE
    def increasingTriplet(self, nums):
        for i in xrange(len(nums) - 2):
            stack = [nums[i]]
            for j in xrange(i + 1, len(nums)):
                if len(stack) > 1 and stack[-1] > nums[j] and stack[-2] < nums[j]:
                    stack.pop()
                    stack.append(nums[j])
                elif nums[j] > stack[-1]:
                    stack.append(nums[j])
                if len(stack) >= 3:
                    return True
        return False
    
    # !! dynamic programming: dp[i] = longest length of increasing subsequece ending at i
    # O(N2) time, O(N) space, TLE
    def increasingTriplet(self, nums):
        if len(nums) < 3:
            return False
        dp = [1 for i in range(len(nums))]
        for end in xrange(1, len(nums)):
            for start in xrange(end):
                if nums[end] > nums[start]:
                    dp[end] = max(dp[end], dp[start] + 1)
            if dp[end] >= 3:
                return True
        return False
    
    # !!! two marker: O(N) time, O(1) space
    def increasingTriplet(self, nums):
        if len(nums) < 3:
            return False
        min1, min2 = float('inf'), float('inf')
        for num in nums:
            if num <= min1:
                min1 = num
            elif num <= min2:
                min2 = num
            else:
                return True
        return False
        