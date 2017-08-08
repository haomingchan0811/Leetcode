# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # recursive dfs: O(N)time, O(h) space
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        def dfs(root, ret):
            if root:
                ret.append(root.val)
                dfs(root.left, ret)
                dfs(root.right, ret)
        ret = []
        dfs(root, ret)
        return ret
    
    # iterative, stack: O(N)time, O(N) space
    def preorderTraversal(self, root):
        ret, stack = [], [root]
        while stack:
            node = stack.pop()
            if node:
                ret.append(node.val)
                stack.append(node.right)
                stack.append(node.left)
        return ret
        