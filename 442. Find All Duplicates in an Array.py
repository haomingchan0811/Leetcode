from collections import Counter
class Solution(object):
    
    # hash table: O(N) time & space
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        duplicates = filter(lambda (key,val): val == 2, Counter(nums).items())
        return map(lambda (x,y): x, duplicates)
    
    # sort: O(NlogN) time, no space
    def findDuplicates(self, nums):
        nums.sort()
        ret = []
        for i in xrange(1, len(nums)):
            if nums[i] == nums[i-1]:
                ret.append(nums[i])
        return ret
    
    # flagging: O(N) time, no space
    def findDuplicates(self, nums):
        ret = []
        for num in nums:
            if nums[abs(num)-1] < 0: ret.append(abs(num))
            nums[abs(num)-1] *= -1
        return ret
            
       
    
        
        