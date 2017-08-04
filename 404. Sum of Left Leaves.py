# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # dfs: O(N) time, O(h) space
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def dfs(root, isLeft):
            curr = 0
            if (not root.left) and (not root.right):
                return root.val if isLeft else 0
            if root.left:
                curr += dfs(root.left, True)
            if root.right:
                curr += dfs(root.right, False)
            return curr
        
        return dfs(root, False) if root else 0

    # bfs, queue: O(N) time & space
    def sumOfLeftLeaves(self, root):
        if not root:
            return 0
        queue, ret = [(root, False)], 0
        for node, isLeft in queue:
            if not node.left and not node.right and isLeft:
                ret += node.val
            if node.left:
                queue.append((node.left, True))
            if node.right:
                queue.append((node.right, False))
        return ret
        
            
        