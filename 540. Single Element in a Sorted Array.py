class Solution(object):
    
    # hash table: O(N) time & space
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = {}
        for num in nums:
            cnt[num] = cnt.get(num, 0) + 1
        for num, count in cnt.items():
            if count & 1:
                return num
    
    # bit manipulation: O(N) time, O(1) space
    def singleNonDuplicate(self, nums):
        ret = 0 
        for num in nums:
            ret ^= num
        return ret
        