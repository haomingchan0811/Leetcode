# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import heapq
class Solution(object):
    
    # bfs and heap: O(NlogN) time, O(N) space
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        h, queue = [], [root]
        for node in queue:
            heapq.heappush(h, node.val)
            queue += filter(None, [node.left, node.right])
        ret = float('inf')
        prev = heapq.heappop(h)
        while h:
            curr = heapq.heappop(h)
            ret = min(ret, curr - prev)
            prev = curr
        return ret
    
    # inorder traversal of BST is sorted: O(N) time, O(1) space
    def getMinimumDifference(self, root):
        def inorder(root):
            if root is None:
                return 
            inorder(root.left)
            if self.prev is not None:
                self.ret = min(self.ret, root.val - self.prev)
            self.prev = root.val
            inorder(root.right)
    
        self.ret = float('inf')
        self.prev = None
        inorder(root)
        return self.ret
        