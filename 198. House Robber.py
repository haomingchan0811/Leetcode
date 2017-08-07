class Solution(object):
    
    # dynamic programming: O(N) time, O(1) space
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ret = (0, 0)  # (do not rub this house, rob)
        for num in nums:
            ret = (max(ret), ret[0] + num)   
        return max(ret)
        