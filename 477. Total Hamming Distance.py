class Solution(object):
    
    # brute force: O(n2) time, O(1) space, TLE
    def totalHammingDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def hammingDistance(num1, num2):
            return bin(num1 ^ num2).count('1') 
        
        ret = 0
        for i in xrange(len(nums)):
            for j in xrange(i + 1, len(nums)):
                ret += hammingDistance(nums[i], nums[j])
        return ret 

    # math, count 1 in every bit: O(n) time, O(1) space
    def totalHammingDistance(self, nums):
        bits = {i:0 for i in range(32)}
        for num in nums:
            curr = bin(num)[2:]
            for i in xrange(len(curr)):
                bits[len(curr) - i - 1] += int(curr[i] == '1')
        ret = 0
        for count in bits.values():
            ret += count * (len(nums) - count)
        return ret 