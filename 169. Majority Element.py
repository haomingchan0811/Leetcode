class Solution(object):
    
    # sort: O(NlogN) time, O(1) space
    def majorityElement(self, nums):
        nums.sort()
        return nums[len(nums) / 2]
    
    # hash table: O(N) time & space
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = {}
        majority = len(nums) / 2
        for num in nums:
            count[num] = count.get(num, 0) + 1
            if count[num] > majority:
                return num
        return 0
    
    # Moore's voting algorithm: O(N) time, O(1) space
    def majorityElement(self, nums):
        count, curr = 0, None
        for num in nums:
            if count == 0:
                curr = num
                count = 1
            else:
                count += 1 if curr == num else -1 
        return curr
    