# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # recursive dfs: O(N) time, O(h) space
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        def dfs(root, curr):
            if not root.left and not root.right:
                self.ret.append(curr + str(root.val))
                return 
            if root.left:
                dfs(root.left, curr + str(root.val) + '->')
            if root.right:
                dfs(root.right, curr + str(root.val) + '->')
        self.ret = []
        if root is None:
            return self.ret
        dfs(root, "")
        return self.ret
    
    # bfs queue: O(N) time, O(N) space
    def binaryTreePaths(self, root):
        ret, queue = [], [(root, '')]
        if not root:
            return ret
        for elem in queue:
            node = elem[0]
            if not node.left and not node.right:
                ret.append(elem[1] + str(node.val))
            queue += [(n, elem[1] + str(node.val) + '->') for n in [node.left, node.right] if n]
        return ret
        