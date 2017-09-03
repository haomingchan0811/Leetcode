# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # flatten and two pointers: O(N) time, O(N) space
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        def flatten(root, nums):
            if root is None:
                return 
            flatten(root.left, nums)
            nums.append(root.val)
            flatten(root.right, nums)
            
        if root is None:
            return False
        nums = []
        flatten(root, nums)
        i, j = 0, len(nums) - 1
        while i < j:
            if nums[i] + nums[j] == k:
                return True
            elif nums[i] + nums[j] < k:
                i += 1
            else:
                j -= 1
        return False

    # ! one pass dfs, hash set: O(N) time, O(N) space
    def findTarget(self, root, k):
        def helper(root, nums):
            if root is None:
                return False
            if k - root.val in nums:
                return True
            nums.add(root.val)
            return helper(root.left, nums) or helper(root.right, nums)

        nums = set()
        return helper(root, nums)
        
        