class Solution(object):
    
    # Naive brute force: O(N2) time, O(1) space, 21.17%
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in xrange(len(nums)):
            for j in xrange(i+1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]
       
    # Sort and Two pointer: O(NlogN) time, O(N) space, 57.72%
    def twoSum(self, nums, target):
        nums = zip(nums, range(len(nums)))
        nums.sort()
        i, j = 0, len(nums) - 1
        while i < j:
            if nums[i][0] + nums[j][0] == target:
                return [min(nums[i][1], nums[j][1]), max(nums[i][1], nums[j][1])]
            elif nums[i][0] + nums[j][0] < target:
                i += 1
            else:
                j -= 1
     
    # Hashtable: O(N) time & space, 77.17%, ok
    def twoSum(self, nums, target):
        table = {}
        for i in xrange(len(nums)):
            if nums[i] in table:
                return [table[nums[i]], i]
            else:
                table[target - nums[i]] = i
        