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
    
    # dfs, if subtree t has both p and q, t is LCA: O(N) time, O(N) space
    def lowestCommonAncestor(self, root, p, q):
        if root in [p, q, None]:
            return root
        l = self.lowestCommonAncestor(root.left, p, q)
        r = self.lowestCommonAncestor(root.right, p, q)
        if l and r:
            return root
        return l if l else r
    
    # bst dfs: O(N) time, O(1) space
    def lowestCommonAncestor(self, root, p, q):
        if (root.val - p.val) * (root.val - q.val) <= 0:
            return root
        if p.val < root.val:
            return self.lowestCommonAncestor(root.left, p, q)
        return self.lowestCommonAncestor(root.right, p, q)
        