# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque
class Solution(object):
    
    # BFS, queue: O(N) time & space
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root == None:
            return []
        queue, ret = deque([root]), []
        while queue:
            size, levelMax = len(queue), float('-inf')
            while size:
                size = size - 1
                node = queue.popleft()
                levelMax = max(levelMax, node.val)
                queue += filter(None, [node.left, node.right])
            ret.append(levelMax)
        return ret
    
    # DFS, recursive: O(N) time & space
    def largestValues(self, root):
        def dfs(root, level, ret):
            if root == None:
                return
            if len(ret) == level:
                ret.append(root.val)
            else:
                ret[level] = max(ret[level], root.val)
            for node in [root.left, root.right]:
                dfs(node, level + 1, ret)
                
        ret = []
        dfs(root, 0, ret)
        return ret
            
            
        