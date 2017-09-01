from collections import deque
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # bfs, queue: O(N) time, O(1) space
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root is None:
            return []
        queue, ret = deque([root]), []
        while queue:
            level_size = len(queue)
            ret.append([x.val for x in queue])
            while level_size:
                level_size -= 1
                node = queue.popleft()
                queue += filter(None, [node.left, node.right])
        return ret[::-1]
            
        