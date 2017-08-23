class Solution(object):
    
    # sort: O(NlogN) time, O(1) space
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums.sort()
        ret, sums = [], nums[0] - len(nums)
        for i in xrange(1, len(nums)):
            sums += nums[i] - i
            if nums[i] == nums[i - 1]:
                ret.append(nums[i])
        ret.append(ret[0] - sums)
        return ret
            
    # hash table: O(N) time, O(N) space
    def findErrorNums(self, nums):
        ret, count, sums = [], {}, 0
        for i in xrange(len(nums)):
            sums += nums[i] - (i + 1)
            if nums[i] in count:
                ret.append(nums[i])
            count[nums[i]] = 1  
        ret.append(ret[0] - sums)
        return ret
    
    # ! negate trick: O(N) time, O(1) space
    def findErrorNums(self, nums):
        ret, count = [], {}
        for i in xrange(len(nums)):
            n = abs(nums[i]) - 1
            if nums[n] < 0:
                ret.append(n + 1)
            else:
                nums[n] *= -1
        for i, num in enumerate(nums):
            if num > 0:
                ret.append(i + 1)
                break
        return ret