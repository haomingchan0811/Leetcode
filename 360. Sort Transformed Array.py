class Solution(object):
    
    # brute force: O(NlogN) time, no space
    def sortTransformedArray(self, nums, a, b, c):
        """
        :type nums: List[int]
        :type a: int
        :type b: int
        :type c: int
        :rtype: List[int]
        """
        ret = map(lambda x: a*(x**2) + b*x + c, nums)
        ret.sort()
        return ret
    
    # two pointers: O(N) time, no space
    # If we plot the transformed array, it would form a parabola. If a > 0, the two ends will be higher than the center. So do a merge sort - move from both ends of the transformed array towards the center and if a > 0, choose the bigger element and put it at the end of the resulting array, i.e. fill the array from right to left. If a < 0, merge the elements from left to right.
    def sortTransformedArray(self, nums, a, b, c):
        nums = map(lambda x: a*(x**2) + b*x + c, nums)
        i, j, ret = 0, len(nums)-1, [0] * len(nums)
        k, sign = (i, -1) if a < 0 else (j, 1)
        while i <= j:
            if nums[i] * sign > nums[j] * sign:
                ret[k] = nums[i]
                i += 1
            else:
                ret[k] = nums[j]
                j -= 1
            k -= sign
        return ret
        