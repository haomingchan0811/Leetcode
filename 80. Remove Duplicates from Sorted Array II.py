class Solution(object):
    
    # two pointer: O(N) time, O(1) space
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums == []:
            return 0
        i, count = 0, 1
        for j in xrange(1, len(nums)):
            if nums[j] != nums[i]:
                i += 1
                nums[i] = nums[j]
                count = 1
            elif nums[j] == nums[i] and count < 2:
                count += 1
                i += 1
                nums[i] = nums[j]
        return i + 1                    
        