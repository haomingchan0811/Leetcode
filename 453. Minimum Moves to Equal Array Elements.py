class Solution(object):
    
    # math: increase n-1 elem by 1 == decrease the maxElem by 1
    # O(N) time, O(1) space
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        minElem = min(nums)
        ret = 0
        for num in nums:
            ret += num - minElem
        return ret
            
        