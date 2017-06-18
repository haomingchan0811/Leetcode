# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque

class Solution(object):
    
    # BFS: O(N) time & space
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root: return 0
        queue, depth = deque([root]), 0
        while queue:
            depth, size = depth+1, len(queue)
            while size:
                node, size = queue.popleft(), size-1
                queue += filter(None, [node.left, node.right])
        return depth
        
    # DFS: O(N) time & space
    def maxDepth(self, root):
        return self.dfs(root, 0)
    
    def dfs(self, root, depth):
        if not root: return depth
        leftDepth = self.dfs(root.left, depth+1)
        rightDepth = self.dfs(root.right, depth+1)
        return max(leftDepth, rightDepth)
    
    # DFS Pythonic: O(N) time & space
    def maxDepth(self, root):
        if not root: return 0
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))
        
        
        
            