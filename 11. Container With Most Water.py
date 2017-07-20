class Solution(object):
    
    # brute force: O(N2) time, O(1) space, TLE
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        ret = 0
        for i in xrange(len(height)):
            for j in xrange(i + 1, len(height)):
                ret = max(ret, (j - i) * min(height[i], height[j]))
        return ret

    # two pointers: O(N) time, O(1) space
    def maxArea(self, height):
        i, j = 0, len(height) - 1
        ret = j * min(height[j], height[i])
        while i < j:
            if height[j] > height[i]:
                i += 1
                while i < j and height[i] <= height[i - 1]:
                    i += 1
            else:
                j -= 1
                while i < j and height[j] <= height[j + 1]:
                    j -= 1
            ret = max(ret, (j - i) * min(height[i], height[j]))
        return ret
    
    # two pointers, more elegant: O(N) time, O(1) space
    def maxArea(self, height):
        i, j, ret = 0, len(height) - 1, 0
        while i < j:
            ret = max(ret, (j - i) * min(height[i], height[j]))
            if height[j] > height[i]:
                i += 1
            else:
                j -= 1
        return ret
        