class Solution(object):
    
    # brute force: O(N2) time, no space, TLE
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in xrange(len(numbers)):
            for j in xrange(i + 1, len(numbers)):
                if numbers[j] + numbers[i] == target:
                    return [i + 1, j + 1]
        return [-1, -1]
    
    # binary search: O(NlogN) time, O(1) space, TLE
    def twoSum(self, numbers, target):
        for i, num in enumerate(numbers):
            low, high = i + 1, len(numbers) - 1
            while low + 1 < high:
                mid = low + (high - low) / 2
                if numbers[mid] + num == target:
                    return [i + 1, mid + 1]
                elif numbers[mid] + num < target:
                    low = mid
                else:
                    high = mid
            if numbers[low] + num == target:
                return [i + 1, low + 1]
            if numbers[high] + num == target:
                return [i + 1, high + 1]
        return [-1, -1]
    
    # hash table: O(N) time & space
    def twoSum(self, numbers, target):
        index = {}
        for i, num in enumerate(numbers):
            if num in index:
                return [index[num], i + 1]
            else:
                index[target - num] = i + 1
        return [-1, -1]
                    
    # two pointers: O(N) time, O(1) space
    def twoSum(self, numbers, target):
        low, high = 0, len(numbers) - 1
        while low < high:
            currSum = numbers[low] + numbers[high]
            if currSum == target:
                return [low + 1, high + 1]
            elif currSum < target:
                low += 1
            else:
                high -= 1
        return [-1, -1]
                    