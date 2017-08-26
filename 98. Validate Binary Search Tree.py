# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # inorder traversal: O(N) time, O(N) space
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def inorder(root):
            if root:
                inorder(root.left)
                self.nodes.append(root.val)
                inorder(root.right)
        self.nodes = []
        inorder(root)
        for i in xrange(1, len(self.nodes)):
            if self.nodes[i] <= self.nodes[i - 1]:
                return False
        return True
    
    # !! inorder traversal with Prev node: O(N) time, O(1) space
    def isValidBST(self, root):
        def inorder(root):
            if root is None:
                return True
            if not inorder(root.left):
                return False
            if self.prev is None or root.val > self.prev:
                self.prev = root.val
                return inorder(root.right)
            return False
        self.prev = None
        return inorder(root)

    # !! dfs, check interval: O(N) time, O(1) space
    def isValidBST(self, root):
        def dfs(root, minVal, maxVal):
            if root is None:
                return True
            if not minVal < root.val < maxVal:
                return False
            return dfs(root.left, minVal, root.val) and dfs(root.right, root.val, maxVal)
               
        return dfs(root, float('-inf'), float('inf'))

        