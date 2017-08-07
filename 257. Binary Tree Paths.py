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
        def dfs(root, curr, ret):
            string = '%s%d->' % (curr, root.val)
            if not root.left and not root.right:
                ret.append(string[:-2])
            if root.left:
                dfs(root.left, string, ret)
            if root.right:
                dfs(root.right, string, ret)
        ret = []
        if not root:
            return ret
        dfs(root, "", ret)
        return ret
    
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
        