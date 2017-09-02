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
        queue = deque([root])
        while queue:
            levelSize, prev = len(queue), None
            while levelSize:
                levelSize -= 1
                node = queue.popleft()
                node.next = prev
                prev = node
                queue += filter(None, [node.right, node.left])
        
        
    # DFS: O(N) time, O(1) space
    def connect(self, root):
        level_head, curr = root, None
        while level_head:
            curr, nextLevel_head = level_head, None
            while curr:
                if curr.left:
                    if nextLevel_head is None:    # bug: define head of nextlevel
                        nextLevel_head = curr.left
                    if curr.right:
                        curr.left.next = curr.right
                    else:
                        temp = curr.next
                        while temp:
                            if temp.left:
                                curr.left.next = temp.left
                                break
                            elif temp.right:
                                curr.left.next = temp.right
                                break
                            temp = temp.next
                if curr.right:
                    if nextLevel_head is None:    # bug: define head of nextlevel
                        nextLevel_head = curr.right
                    temp = curr.next
                    while temp:
                        if temp.left:
                            curr.right.next = temp.left
                            break
                        elif temp.right:
                            curr.right.next = temp.right
                            break
                        temp = temp.next
                curr = curr.next
            level_head = nextLevel_head
    
    
    # !! more elegant, BFS: O(N) time, O(1) space
    def connect(self, root):
        while root:
            child_dummy = TreeLinkNode(-1)
            child_head = child_dummy
            while root:
                if root.left:
                    child_head.next = root.left
                    child_head = child_head.next
                if root.right:
                    child_head.next = root.right
                    child_head = child_head.next
                root = root.next
            root = child_dummy.next
            
        