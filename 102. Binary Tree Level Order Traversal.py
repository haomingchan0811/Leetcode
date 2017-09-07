# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # BFS: O(N) time & space
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root is None:
            return []
        queue, ret = deque([root]), []
        while queue:
            levelSize = len(queue)
            temp = []
            while levelSize:
                node = queue.popleft()
                levelSize -= 1
                temp.append(node.val)
                queue += filter(None, [node.left, node.right])
            ret.append(temp)
        return ret
    
    # Pythonic BFS: O(N) time & space
    def levelOrder(self, root):
        if root == None: return []
        level, ret = [root], []
        while level:
            ret.append([node.val for node in level])
            level = [kid for node in level for kid in [node.left, node.right] if kid]
        return ret
            