class Solution(object):
    
    # brute force: O(n3) time, O(n) space, TLE
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for length in xrange(len(nums), -1, -1):
            for i in xrange(0, len(nums) - length + 1):
                j = i + length
                if nums[i:j].count(0) * 2 == length:
                    return length
        return 0
    
    # rangeSum: O(n2) time, O(n) space, TLE
    def findMaxLength(self, nums):
        zeros = [0]
        for i in xrange(len(nums)):
            zeros.append(zeros[i] + (1 if nums[i] == 0 else 0))
            
        for length in xrange(len(nums), 0, -1):
            for i in xrange(0, len(nums) - length + 1):
                j = i + length
                if (zeros[j] - zeros[i]) * 2 == length:
                    return length
        return 0
                
    # !! hash table: when rangeSum (-1 when 0, +1 when 1) are equal, a qualified subarray is found
    # O(n) time, O(n) space
    def findMaxLength(self, nums):
        index = {0: -1}
        count, ret = 0, 0
        for i in xrange(len(nums)):
            count += 1 if nums[i] == 1 else -1
            if count in index:
                ret = max(ret, i - index[count])
            else:
                index[count] = i
        return ret
        