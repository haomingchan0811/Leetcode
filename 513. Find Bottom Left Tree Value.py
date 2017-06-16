# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque

class Solution(object):
    
    # naive bfs: O(N) time & space, 67.24%
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None: return None
        ret = root.val
        queue = deque([root])
        while len(queue):
            size, leftmost = len(queue), True
            while size:
                curr, size = queue.popleft(), size - 1
                if curr.left: 
                    if leftmost:
                        ret, leftmost = curr.left.val, False
                    queue.append(curr.left)
                if curr.right:
                    if leftmost:
                        ret, leftmost = curr.right.val, False
                    queue.append(curr.right)
        return ret
            
    # bfs, right-to-left: O(N) time & space, 28.62%
    def findBottomLeftValue(self, root):
        if root == None: return root
        queue = [root]
        for node in queue:
            queue += filter(None, [node.right, node.left])
        return queue[-1].val
        