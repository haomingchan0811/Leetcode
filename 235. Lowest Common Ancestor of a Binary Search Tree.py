# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # dfs and hashtable, save the path: O(N) time & space
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        def dfs(root, target, path):
            path.append(root)
            if root == target:
                return
            elif root.val > target.val:
                dfs(root.left, target, path)
            else:
                dfs(root.right, target, path)
        
        path_p, path_q = [], []
        dfs(root, p, path_p)
        dfs(root, q, path_q)
        path_p = {node:1 for node in path_p}
        for node in path_q[::-1]:
            if node in path_p:
                return node
        return None

    # bst dfs: O(N) time, O(1) space
    def lowestCommonAncestor(self, root, p, q):
        while (p.val - root.val) * (q.val - root.val) > 0:
            if p.val - root.val > 0:
                root = root.right
            else:
                root = root.left
        return root
        