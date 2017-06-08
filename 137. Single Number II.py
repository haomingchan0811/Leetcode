class Solution(object):
    
    # Hashtable: O(N) time & space, 92.93%, ok
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        counter = {}
        for num in nums:
            counter[num] = counter.get(num, 0) + 1
        for num, cnt in counter.items():
            if cnt == 1:
                return num
        
    # Bit Manipulation: O(N) time, O(1) space, 9.51%
    def singleNumber(self, nums):
        bits = [0 for i in xrange(32)]
        for num in nums:
            for i in xrange(32):
                bits[i] += num & (1 << i)
        ret = -(1 << 31) if (bits[i] % 3) else 0
        for i in xrange(31):
            ret += (1 << i) if (bits[i] % 3) else 0
        return ret
    
    # Math: O(N) time & space, 87.07%
    def singleNumber(self, nums):
        unique = set(nums)
        return (sum(unique) * 3 - sum(nums)) / 2
