from collections import Counter
class Solution(object):
    
    # Count: O(N) time & space
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        cnt, i = Counter(nums), 0
        for color in range(3):
            tempCnt = 0
            while tempCnt < cnt[color]: 
                nums[i], i, tempCnt = color, i+1, tempCnt+1
    
    # Two pointer: O(N) time, O(1) space
    def sortColors(self, nums):
        i = 0
        for j in xrange(len(nums)):
            if nums[j] == 0:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
        for j in xrange(i, len(nums)):
            if nums[j] == 1:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
        
            
            
        