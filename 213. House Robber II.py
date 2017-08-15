class Solution(object):
    
    # dp, straight forward two cases: O(N) time, O(1) space
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        if len(nums) == 1:    # bug: corner case
            return nums[0]
        robFirst, notRobFirst = (0, nums[0]), (0, 0)   # (notRob, rob)
        for i, num in enumerate(nums):
            if i != 0:
                robFirst = (max(robFirst), robFirst[0] + num)
                notRobFirst = (max(notRobFirst), notRobFirst[0] + num)
                
        return max(robFirst[0], max(notRobFirst))
        