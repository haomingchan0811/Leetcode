class Solution(object):
    
    # binary search: O(logN) time, O(1) space
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        low, high = 0, len(nums) - 1
        while low + 1 < high:
            mid = low + (high - low) / 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                low = mid
            else:
                high = mid
        if nums[high] < target:
            return high + 1
        elif nums[high] == target or nums[low] < target:
            return high
        return low
    
    # !! brilliant: O(N) time, O(1) space
    def searchInsert(self, nums, target):
        count = 0
        for num in nums:
            if num >= target:
                break
            count += 1
        return count