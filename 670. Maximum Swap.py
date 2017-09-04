class Solution(object):
    
    # two pointer: O(N) time, O(N) space
    def maximumSwap(self, num):
        """
        :type num: int
        :rtype: int
        """
        nums = list(str(num))
        for i in xrange(len(nums)):
            max_idx = i
            for j in xrange(i + 1, len(nums)):
                if nums[max_idx] <= nums[j]: # bug: <=
                    max_idx = j
            # if max_idx != i:   # bug: nums[i] and nums[max_idx] can be the same 
            if nums[i] != nums[max_idx]:    
                nums[i], nums[max_idx] = nums[max_idx], nums[i]
                return int(''.join(nums))
        return num
            
            