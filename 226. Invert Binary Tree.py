# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # dfs: O(N) time, O(N) space
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root:
            root.left, root.right = root.right, root.left
            self.invertTree(root.left)
            self.invertTree(root.right)
        return root
    
    # bfs: O(N) time, O(N) space
    def invertTree(self, root):
        if root == None:    # corner case
            return None
        queue = [root]
        for node in queue:
            node.left, node.right = node.right, node.left
            queue += filter(None, [node.left, node.right])
        return root
                
        