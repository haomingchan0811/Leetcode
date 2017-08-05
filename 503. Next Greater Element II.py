class Solution(object):
    
    # duplicate the list and brute force: O(n2) time, O(n) space, TLE
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums1 = nums + nums
        ret = [-1 for i in xrange(len(nums))]
        for i in xrange(len(nums)):
            for j in xrange(i + 1, len(nums1)):
                if nums[i] < nums1[j]:
                    ret[i] = nums1[j]
                    break
        return ret
    
    # stack: O(n) time, O(n) space
    def nextGreaterElements(self, nums):
        ret, stack = [-1 for num in nums], []
        for i, num in enumerate(nums):
            while stack and stack[-1][1] < num:
                ret[stack.pop()[0]] = num
            stack.append((i, num))
        for num in nums:
            if len(stack) == 0:
                break
            while stack and stack[-1][1] < num:
                ret[stack.pop()[0]] = num
        return ret
                    
        