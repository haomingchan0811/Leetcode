# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # postorder traversal: O(N) time, O(1) space
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        def postorder(root):
            if root:
                postorder(root.right)
                root.val += self.prev
                self.prev = root.val
                postorder(root.left)
        self.prev = 0
        postorder(root)
        return root