    # rangeSum: O(n2) time, O(1) space, TLE for Python
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        ret = 0
        for i in xrange(1, len(nums)):  # num[i]: range sum from begining to i 
            nums[i] += nums[i - 1]
        for end in xrange(len(nums)):
            ret += 1 if nums[end] == k else 0
            for start in xrange(end):
                if nums[end] - nums[start] == k:
                    ret += 1
        return ret
    
    # better rangeSum: O(n2) time, O(1) space, TLE for Python
    def subarraySum(self, nums, k):
        ret = 0
        for end in xrange(len(nums)):
            nums[end] += nums[end - 1] if end != 0 else 0
            ret += 1 if nums[end] == k else 0
            for start in xrange(end):
                if nums[end] - nums[start] == k:
                    ret += 1
        return ret
    
    # hash map: O(n) time, O(N) space, TLE
    def subarraySum(self, nums, k):
        ret, sums, count = 0, 0, {0: 1}
        for num in nums:
            sums += num
            ret += count.get(sums - k, 0)
            # count[sums] = 1   # bug: can have multiple satisfied range sum
            count[sums] = count.get(sums, 0) + 1
        return ret