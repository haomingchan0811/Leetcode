class Solution(object):
    
    # !! binary search and greedy: O(n*logSum) time, O(1) space
    def splitArray(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: int
        """
        def valid(nums, m, mid):
            sums, interval = 0, 1
            for num in nums:
                sums += num
                if sums > mid:     # need another new interval
                    sums = num
                    interval += 1
                    if interval > m:        # cannot accommodate with mid
                        return False
            return True              
        
        low = max(nums)
        high = sum(nums)            # boundry is [max individual, sum_of_all]
        while low + 1 < high:
            mid = low + (high - low) / 2
            if valid(nums, m, mid):   # if mid can work for m intervals, then we can further minimize mid
                high = mid
            else:
                low = mid
        if valid(nums, m, low):
            return low
        return high