class Solution(object):
    
    # sort and two pointers: O(N2) time, O(1) space
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        ret = []
        for i in xrange(len(nums) - 2):  # clever end point
            if i > 0 and nums[i] == nums[i - 1]:  # bug: while (WRONG) -> if
                continue
            head, tail = i + 1, len(nums) - 1
            while head < tail:
                if nums[head] + nums[tail] + nums[i] == 0:
                    ret.append([nums[i], nums[head], nums[tail]])
                    head, tail = head + 1, tail - 1
                    while head < tail and nums[head - 1] == nums[head]:
                        head += 1
                    while tail > head and nums[tail + 1] == nums[tail]:
                        tail -= 1
                elif nums[head] + nums[tail] + nums[i] < 0:
                    head += 1
                else:
                    tail -= 1
        return ret
                
        