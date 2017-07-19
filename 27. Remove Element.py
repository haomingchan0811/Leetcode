class Solution(object):
    
    # Two pointers1 (may include unnecessary copy): O(N) time, O(1) space
    def removeElement(self, nums, val):
        i = 0
        for j in xrange(len(nums)):
            if nums[j] != val:
                nums[i] = nums[j]
                i += 1
        return i 
    
    # Two pointers2 (sub-optimal): O(N) time, O(1) space
    def removeElement(self, nums, val):
        i, n = 0, len(nums)
        while i < n:
            if nums[i] == val:
                nums[i] = nums[n - 1]
                n -= 1   # replace last one and decrease length by 1
            else:
                i += 1
        return i 
    
    # Two pointers3 (optimal): O(N) time, O(1) space
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i, j = 0, len(nums) - 1
        while i <= j:
            while i <= j and nums[i] != val:
                i += 1
            while i <= j and nums[j] == val:
                j -= 1
            if i <= j:
                nums[i] = nums[j]
                i, j = i + 1, j - 1
        return i 
                
                
        