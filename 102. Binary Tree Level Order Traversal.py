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
        if root == None: return []
        queue, ret, i = [root], [], 0
        while i < len(queue):
            levelSize, level = len(queue)-i, []
            while levelSize:
                root, levelSize = queue[i], levelSize-1
                level.append(root.val)
                queue += filter(None, [root.left, root.right])
                i += 1
            ret.append(level)
            i += levelSize
        return ret
    
    # Pythonic BFS: O(N) time & space
    def levelOrder(self, root):
        if root == None: return []
        level, ret = [root], []
        while level:
            ret.append([node.val for node in level])
            level = [kid for node in level for kid in [node.left, node.right] if kid]
        return ret
            