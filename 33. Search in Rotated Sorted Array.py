class Solution(object):
    
    # binary search: O(logN) time, O(1) space
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        low, high = 0, len(nums) - 1
        while low <= high:
            mid = low + (high - low) / 2 
            if nums[mid] == target:
                return mid
            if nums[mid] >= nums[low]:               # bug: '>' should be >='
                if nums[low] <= target < nums[mid]:  # bug: '<' should be <='
                    high = mid - 1
                else:
                    low = mid + 1
            else:
                if nums[mid] < target <= nums[high]:  # bug: '<' should be <='
                    low = mid + 1
                else:
                    high = mid - 1
        return -1
                