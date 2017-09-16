class Solution(object):
    
    # copy: O(N) time, O(N) space
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        k %= len(nums)     # bug: k may be larger than length of nums
        temp = nums[-k:] + nums[:-k]
        for i in xrange(len(nums)):
            nums[i] = temp[i]
    
    
    # simulation: O(kN) time, O(1) space, TLE
    def rotate(self, nums, k):
        k %= len(nums)     # bug: k may be larger than length of nums
        while k:
            temp = nums[-1]
            k -= 1
            for i in xrange(len(nums) - 1, 0, -1):
                nums[i] = nums[i - 1]
            nums[0] = temp
    
    
    # replace in order: O(N) time, O(1) space
    def rotate(self, nums, k):
        if len(nums) == 0:
            return 
        currIdx, prev, visited = 0, nums[0], set()

        # starting from first elem, shift in order
        while len(visited) < len(nums):
            if currIdx in visited:
                currIdx += 1
                prev = nums[currIdx]
                
            visited.add(currIdx)
            idx = (currIdx + k) % len(nums)
            temp = nums[idx]
            nums[idx] = prev
            currIdx, prev = idx, temp

    # replace in order: O(N) time, O(1) space
    def rotate(self, nums, k):
        if len(nums) == 0:
            return 
        k %= len(nums)     # bug: k may be larger than length of nums
        nums[:-k] = reversed(nums[:-k])
        nums[-k:] = reversed(nums[-k:])
        nums[:] = reversed(nums)
                            
        
        