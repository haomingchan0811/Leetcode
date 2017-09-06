# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque
class Solution(object):
    
    # bfs, queue: O(NlogN) time & space
    def verticalOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        maps = {}
        if root is None:
            return []
        queue = [(root, 0)]
        for node, col in queue:
            maps[col] = maps.get(col, []) + [node.val]
            if node.left:
                queue.append((node.left, col - 1))
            if node.right:
                queue.append((node.right, col + 1))
        maps = sorted(maps.items(), key = lambda x:x[0])
        return [x[1] for x in maps]
    
#     # WRONG!!! order matters (If two nodes are in the same row and column, the order should be from left to right.)
#     # dfs: O(NlogN) time & space
#     def verticalOrder(self, root):
#         def dfs(root, col, ans):
#             if root == None:
#                 return
#             ans[col] = ans.get(col, []) + [root.val]
#             dfs(root.left, col - 1, ans)
#             dfs(root.right, col + 1, ans)
        
#         ans = dict()
#         dfs(root, 0, ans)
#         sorted_ans = sorted(ans.items(), key = lambda x: x[0])
#         return map(lambda x: x[1], sorted_ans)
                