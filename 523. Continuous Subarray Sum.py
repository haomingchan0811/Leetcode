class Solution(object):
    
    # rangesum: O(N2) time, O(1) space
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        # bug: k = 0, nums has 0s, k < 0
        for i in xrange(1, len(nums)):
            nums[i] += nums[i - 1]
            
        for i in xrange(1, len(nums)):
            if nums[i] == k == 0 or (k and nums[i] % k == 0):
                return True
            for j in xrange(0, i - 1):
                temp = nums[i] - nums[j]
                if temp == k == 0 or (k and temp % k == 0):
                    return True
        return False
    
    # !! hashmap: store remainder and index, when come across a existed remainder, we found a hit
    # O(N) time, O(min(n, k)) space
    def checkSubarraySum(self, nums, k):
        sums, remainders = 0, {0: -1}
        for i, num in enumerate(nums):
            sums += num
            r = sums % k if k != 0 else sums  # bug: k = 0 
            if r in remainders:
                if i - remainders[r] > 1:
                    return True
            else:
                remainders[r] = i
        return False
        