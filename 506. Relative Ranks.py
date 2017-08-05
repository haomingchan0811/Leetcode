class Solution(object):
    
    # sort: O(NlogN) time, O(N) space
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        medals = {0:"Gold Medal", 1:"Silver Medal", 2:"Bronze Medal"}
        nums = map(lambda (index, num): (num, index), enumerate(nums))
        nums = sorted(nums, reverse = True)
        ret = [0 for i in xrange(len(nums))]
        for i, (_, index) in enumerate(nums):
            ret[index] = medals[i] if i in medals else str(i + 1)
        return ret
        