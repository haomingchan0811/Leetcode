# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # brute force dfs: O(N) time, O(N) space
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        def build(elems):
            if len(elems) == 0:
                return None
            maxElem, index = float('-inf'), None
            for i, elem in enumerate(elems):
                if maxElem <= elem:
                    maxElem, index= elem, i
            root = TreeNode(maxElem)
            root.left = build(elems[:index])
            root.right = build(elems[index + 1:])
            return root
            
        return build(nums)
        