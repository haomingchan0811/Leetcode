class Solution(object):
    
    # sort: O(NlogN) time, no space, 21.03%
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums.sort()
        ret, i = list(), 0
        for j in xrange(1, len(nums)+1):
            if i >= len(nums) or nums[i] > j:
                ret.append(j)
            else:
                while i < len(nums) and nums[i] == j:
                    i += 1
        return ret
            
    # set: O(min(m,n)) time, O(N) space, 77.37%
    def findDisappearedNumbers(self, nums):
        return list(set(nums) ^ set(range(1, len(nums)+1)))
        
    # brilliant: O(N) time, no space, 8.43%
    # for each num in nums, mark the number at index (num-1) as negative
    # after one pass, all index (+1) that are not positive are not visited
    def findDisappearedNumbers(self, nums):
        for num in nums:
            index = abs(num) - 1
            nums[index] = -abs(nums[index])  # bug: avoid double flip 
        return [i+1 for i in xrange(len(nums)) if nums[i] > 0]
            
        