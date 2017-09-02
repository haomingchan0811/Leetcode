from collections import deque
# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # BFS: O(N) time, O(N) space
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if root is None:
            return 
        queue, prev = deque([root]), None
        while queue:
            levelSize = len(queue)
            prev = None
            while levelSize:
                node = queue.popleft()
                node.next = prev
                prev = node
                queue += filter(None, [node.right, node.left])
                levelSize -= 1
    
    # !! DFS: O(N) time, O(1) space
    def connect(self, root):
        prev, curr = root, None
        while prev:
            curr = prev
            while curr:
                if curr.left: 
                    curr.left.next = curr.right
                if curr.right and curr.next:
                    curr.right.next = curr.next.left
                curr = curr.next
            prev = prev.left
        
        
      
        