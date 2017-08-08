# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # dfs: O(N) time, O(h) space
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        def dfs(root, curr):
            if not root:
                return False
            if not root.left and not root.right:
                if curr + root.val == sum:
                    return True
            return dfs(root.left, curr + root.val) | dfs(root.right, curr + root.val)
        return dfs(root, 0)
    
    # iterative bfs: O(N) time, O(N) space
    def hasPathSum(self, root, sum):
        queue = [(root, 0)]
        for node, num in queue:
            if node:
                if not node.left and not node.right and node.val + num == sum:
                    return True
                queue += [(node.left, num + node.val), (node.right, num + node.val)]
        return False
        