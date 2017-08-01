class Solution(object):
    
    # # back tracking, dfs: O(N!) time, O(1) space
    # def permute(self, nums):
    #     """
    #     :type nums: List[int]
    #     :rtype: List[List[int]]
    #     """
    #     def dfs(nums, curr, ret):
    #         if len(curr) == len(nums):
    #             ret.append(curr)
    #         else:
    #             for j in xrange(len(nums)):
    #                 if nums[j] not in curr:
    #                     dfs(nums, curr + [nums[j]], ret)
    #     ret = []
    #     dfs(nums, [], ret)
    #     return ret
    
    # back tracking, dfs: O(N!) time, O(1) space
    def permute(self, nums):
        
        def dfs(nums, curr, i, ret):
            if i == len(nums):
                ret.append(curr)
            else:
                for j in xrange(i, len(nums)):
                    nums[i], nums[j] = nums[j], nums[i]
                    dfs(nums, curr + [nums[i]], i + 1, ret)
                    nums[j], nums[i] = nums[i], nums[j]

        ret = []
        dfs(nums, [], 0, ret)
        return ret
        