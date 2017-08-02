class Solution(object):
    
    # brute force: O(mn) time, O(1) space
    def nextGreaterElement(self, findNums, nums):
        """
        :type findNums: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """
        def findGreater(nums, target):
            found = False
            for num in nums:
                if num == target:
                    found = True
                if found and target < num:
                    return num
            return -1
        ret = []
        for num in findNums:
            ret.append(findGreater(nums, num))
        return ret
    
    # hash table: O(n2) time, O(n) space
    def nextGreaterElement(self, findNums, nums):
        greater = {num: -1 for num in nums}
        for i in xrange(len(nums) - 1):
            for j in xrange(i + 1, len(nums)):
                if nums[j] > nums[i]:
                    greater[nums[i]] = nums[j]
                    break
        return [greater[num] for num in findNums]
    
    # !! stack & hashtable: O(n+m) time, O(n) space
    def nextGreaterElement(self, findNums, nums):
        stack, greater = [], {}
        for num in nums:
            while len(stack) and stack[-1] < num:
                greater[stack.pop()] = num
            stack.append(num)
        while stack:
            greater[stack.pop()] = -1
        return [greater[num] for num in findNums]
                
        