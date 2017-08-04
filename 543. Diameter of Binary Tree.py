# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # dfs, top down: O(N) time, O(h) space
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def maxLen(root, depth):
            if not root:
                return 0
            if not root.left and not root.right:
                return depth
            leftLen = maxLen(root.left, depth + 1)
            rightLen = maxLen(root.right, depth + 1)
            self.maxDepth = max(self.maxDepth, leftLen + rightLen - 2 * depth)
            return max(leftLen, rightLen)
        
        self.maxDepth = 0
        _ = maxLen(root, 0)
        return self.maxDepth
    
    # ! dfs, bottom up: O(N) time, O(h) space
    def diameterOfBinaryTree(self, root):
        def maxLen(root):
            if not root:
                return 0
            leftLen = maxLen(root.left)
            rightLen = maxLen(root.right)
            self.maxDepth = max(self.maxDepth, leftLen + rightLen)
            return max(leftLen, rightLen) + 1
        
        self.maxDepth = 0
        maxLen(root)
        return self.maxDepth
        