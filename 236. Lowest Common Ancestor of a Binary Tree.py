# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
#     # dfs find path & hashmap check LCA: O(N) time, O(2^N) space, MLE
#     def lowestCommonAncestor(self, root, p, q):
#         """
#         :type root: TreeNode
#         :type p: TreeNode
#         :type q: TreeNode
#         :rtype: TreeNode
#         """
#         def dfs(root, target, path, ret):
#             if root == target:
#                 ret += path + [root] 
#                 return 
#             if root.left:
#                 dfs(root.left, target, path + [root], ret)
#             if root.right:
#                 dfs(root.right, target, path + [root], ret)
        
#         path_p, path_q = [], []
#         dfs(root, p, [], path_p)
#         dfs(root, q, [], path_q)
#         path_p = {node:1 for node in path_p}
#         for node in path_q[::-1]:
#             if node in path_p:
#                 return node
#         return None

#     # improved, dfs find path & hashmap check LCA: O(N) time, O(2^N) space, MLE
#     def lowestCommonAncestor(self, root, p, q):
#         def dfs(root, target, path, ret):
#             if root == target:
#                 ret += path + [root] 
#                 return 
#             if root.left:
#                 dfs(root.left, target, path + [root], ret)
#             if root.right:
#                 dfs(root.right, target, path + [root], ret)
        
#         def findLCA(root, target, nodes, curr):
#             if root in nodes:
#                 curr = root
#             if root == target:
#                 self.ret = curr
#                 return 
#             for children in filter(None, [root.left, root.right]):
#                 findLCA(children, target, nodes, curr)
        
#         path_p = []
#         dfs(root, p, [], path_p)        
#         path_p = {node:1 for node in path_p}
        
#         self.ret = None
#         findLCA(root, q, path_p, root)
#         return self.ret

    # dfs, if subtree t has both p and q, t is LCA: O(N) time, O(N) space
    def lowestCommonAncestor(self, root, p, q):
        if root in [None, p, q]:
            return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if left and right:
            return root
        return left if right is None else right
            