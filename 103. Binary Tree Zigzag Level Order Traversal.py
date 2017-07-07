# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque
class Solution(object):
    
    # BFS: O(N) time & space
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root: return []
        queue, ret, left = deque([root]), [], True
        while len(queue):
            level, levelSize = [], len(queue)
            while levelSize:
                node = queue.popleft()
                level.append(node.val)
                queue += filter(None, [node.left, node.right])
                levelSize -= 1
            ret.append(level if left else level[::-1])
            left = not left
        return ret
    
    # !! two stack: O(N) time & space
    def zigzagLevelOrder(self, root):
        if not root: return []
        stack1, stack2 = [root], []
        ret, left = [], True
        while stack1 or stack2:
            level = []
            while stack1:
                node = stack1.pop()
                level.append(node.val)
                stack2 += filter(None, [node.left, node.right])
            ret.append(level)
            level = []
            while stack2:
                node = stack2.pop()
                level.append(node.val)
                stack1 += filter(None, [node.right, node.left])
            if level: ret.append(level)
        return ret
            
        