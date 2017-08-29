class Solution(object):
    
    # brute force: O(N3) time, O(1) space, TLE
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) < 3:
            return None
        ret = float('inf')
        for i in xrange(len(nums)):
            for j in xrange(i + 1, len(nums)):
                for k in xrange(j + 1, len(nums)):
                    sum = nums[i] + nums[j] + nums[k] 
                    if abs(sum - target) < abs(ret - target):
                        ret = sum
        return ret
    
    # sort and binary search: O(N2logN) time, O(1) space, TLE
    def threeSumClosest(self, nums, target):
        if len(nums) < 3:
            return None
        ret = sum(nums[:3])
        nums.sort()
        for i in xrange(len(nums) - 2):
            for j in xrange(i + 1, len(nums) - 1):
                num = target - nums[i] - nums[j]
                low, high = j + 1, len(nums) - 1
                
                while low + 1 < high:
                    mid = low + (high - low) / 2
                    if nums[mid] == num:
                        return target
                    else:
                        if abs(num - nums[mid]) < abs(ret - target):
                            ret = nums[i] + nums[j] + nums[mid] 
                        if nums[mid] < num:
                            low = mid
                        else:
                            high = mid
                if abs(num - nums[low]) < abs(ret - target):
                    ret = nums[i] + nums[j] + nums[low] 
                if abs(num - nums[high]) < abs(ret - target):
                    ret = nums[i] + nums[j] + nums[high] 
        return ret

    # two pointers: O(N2) time, O(1) space, TLE
    def threeSumClosest(self, nums, target):
        if len(nums) < 3:
            return None
        ret = sum(nums[:3])
        nums.sort()
        for i in xrange(len(nums) - 2):
            low, high = i + 1, len(nums) - 1
            while low < high:
                sums = nums[i] + nums[low] + nums[high] 
                if sums == target:
                    return target
                if abs(sums - target) < abs(ret - target):
                    ret = sums
                if sums < target:
                    low += 1
                else:
                    high -= 1
        return ret
        