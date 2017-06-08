class Solution(object):
    
    # Hashtable: O(N) time & space, 19.40%
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        counter = {}
        for num in nums:
            counter[num] = counter.get(num, 0) + 1
        for num, cnt in counter.items():
            if cnt == 1:
                return num

    # Bit manipulation: O(N) time, no space, 69.07%, ok
    def singleNumber(self, nums):
        for i in xrange(1, len(nums)):
            nums[0] ^= nums[i]
        return nums[0]
        
    # Bit Manipulation and Reduce: O(N) time, O(1) space, 55.95%, ok
    def singleNumber(self, nums):
        return reduce(lambda x, y: x ^ y, nums)
        