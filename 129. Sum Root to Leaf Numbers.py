# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # revursive dfs: O(N) time & space
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ret = 0
        self.dfs(root, 0)
        return self.ret
       
    def dfs(self, node, currSum):
        if not node: return
        if not node.left and not node.right: self.ret += currSum*10 + node.val
        self.dfs(node.left, currSum*10 + node.val)
        self.dfs(node.right, currSum*10 + node.val)

    # dfs + stack: O(N) time & space
    def sumNumbers(self, root):
        if not root: return 0
        stack, ret = [(root, root.val)], 0
        while stack:
            node, val = stack.pop()
            if not node.left and not node.right: ret += val
            if node.right: stack.append((node.right, val*10 + node.right.val))
            if node.left: stack.append((node.left, val*10 + node.left.val))
        return ret
