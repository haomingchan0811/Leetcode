class Solution(object):
    
    # brute force with two pointers: O(N2) time, O(1) space, TLE
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        ret = 0
        for i, h in enumerate(heights):
            left, right, length = i - 1, i + 1, 1
            while left >= 0 and heights[left] >= h:
                length, left = length + 1, left - 1
            while right < len(heights) and heights[right] >= h:
                length, right = length + 1, right + 1
            ret = max(ret, length * h)
        return ret
    
    # !!! stack: O(N2) time, O(1) space, TLE
    # https://leetcode.com/problems/largest-rectangle-in-histogram/solution/#approach-5-using-stack-accepted
    def largestRectangleArea(self, heights):
        if len(heights) == 0:
            return 0
        ret = 0
        stack = [(-1, 0)]  # store continuous increasing array
        for i, h in enumerate(heights):
            while stack[-1][0] != -1 and h <= stack[-1][1]:
                idx, height = stack.pop()
                ret = max(ret, height * (i - stack[-1][0] - 1))  # key
            stack.append((i, h))   
            
        while stack[-1][0] != -1:
            idx, height = stack.pop()
            width = len(heights) - stack[-1][0] - 1   # key
            ret = max(ret, height * width)    
        return ret
            
        