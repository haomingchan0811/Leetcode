class Solution(object):
    
    # Two pointers: O(mn) time, O(1) space
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        if len(nums) == 0 or len(nums[0]) == 0:
            return nums
        m, n = len(nums), len(nums[0])
        if m * n != r * c:
            return nums
        ret, row, k = [], [], 0
        for i in xrange(m):
            for j in xrange(n):
                row.append(nums[i][j])
                k += 1
                if k == c:
                    ret.append(row)
                    row, k = [], 0
        return ret
        