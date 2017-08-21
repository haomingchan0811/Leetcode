# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Solution(object):
    
    # dfs: O(N) time, O(N) space
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        def dfs(r1, r2):
            if not r1:
                return r2
            if not r2:
                return r1
            r1.val += r2.val
            r1.left = dfs(r1.left, r2.left)
            r1.right = dfs(r1.right, r2.right)
            return r1  
        return dfs(t1, t2)
    
    # !! iterative stack: O(N) time, O(N) space
    def mergeTrees(self, t1, t2):
        if t1 is None:
            return t2
        stack = [(t1, t2)]
        while stack:
            (r1, r2) = stack.pop()
            if None in [r1, r2]:
                continue
            r1.val += r2.val
            if r1.left is None:
                r1.left = r2.left
            else:
                stack.append((r1.left, r2.left))
            if r1.right is None:
                r1.right = r2.right
            else:
                stack.append((r1.right, r2.right))
        return t1
        
                