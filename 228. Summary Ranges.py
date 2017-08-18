class Solution(object):
    
    # brute force: O(N) time, O(1) space
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        if len(nums) == 0:
            return []
        start = nums[0]
        ret = []
        for i in xrange(1, len(nums)):
            if nums[i] != nums[i - 1] + 1:
                ret.append("%d->%d" % (start, nums[i - 1]) if start != nums[i - 1] else str(start))
                start = nums[i]
        ret.append("%d->%d" % (start, nums[-1]) if start != nums[-1] else str(start))
        return ret
        