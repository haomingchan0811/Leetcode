# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque
class Solution(object):
    
    # dfs: O(N) time, O(h) space
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def dfs(left, right):
            if [left, right].count(None) == 2:
                return True
            elif [left, right].count(None) == 1:
                return False
            elif left.val != right.val:
                return False
            else:
                return dfs(left.left, right.right) & dfs(left.right, right.left)
            
        return dfs(root.left, root.right) if root else True

    # iterative bfs: O(N) time, O(N) space
    def isSymmetric(self, root):
        queue = deque([root])
        while queue:
            for i in xrange(len(queue) / 2):
                node1, node2 = queue[i], queue[-i - 1]
                if [node1, node2].count(None) == 1 or (node1 and node2 and node1.val != node2.val):
                    return False
            levelSize = len(queue)
            while levelSize:
                node = queue.popleft()
                levelSize -= 1
                if node:
                    queue += [node.left, node.right]
        return True
        