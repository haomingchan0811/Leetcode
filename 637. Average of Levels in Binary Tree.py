# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque
class Solution(object):
    
    # BFS, queue: O(N) time & space
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        if root == None:
            return []
        queue, ret = deque([root]), []
        while queue:
            size, size_copy, levelSum = len(queue), len(queue), 0
            while size:
                size -= 1
                node = queue.popleft()
                queue += filter(None, [node.left, node.right])  # bug: append() is list
                levelSum += node.val
            ret.append(float(levelSum) / size_copy)
        return ret
    
    # DFS, recursive: O(N) time & space
    def averageOfLevels(self, root):
        def dfs(root, level, ret, cnt):
            if len(ret) == level:
                ret.append(root.val)
                cnt.append(1)
            else:
                ret[level] += root.val
                cnt[level] += 1
            for node in [root.left, root.right]:
                if node:
                    dfs(node, level + 1, ret, cnt)
                    
        if root == None:
            return []
        ret, cnt = [], []
        dfs(root, 0, ret, cnt)
        return map(lambda (x, y): float(x) / y, zip(ret, cnt))
    
   
        