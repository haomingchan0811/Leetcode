# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
#     # dfs: O(2^N) time, O(logN) space, TLE
#     def rob(self, root):
#         """
#         :type root: TreeNode
#         :rtype: int
#         """
#         def dfs(root, rob):
#             if not root:
#                 return 0
#             if rob:                
#                 return root.val + dfs(root.left, False) + dfs(root.right, False)
#             else:
#                 left = max(dfs(root.left, True), dfs(root.left, False))
#                 right = max(dfs(root.right, True), dfs(root.right, False))
#                 return left + right
        
#         return max(dfs(root, True), dfs(root, False))

    # dfs: O(N) time, O(logN) space, TLE
    def rob(self, root):
        def dfs(root):
            if not root:
                return (0, 0)  # (rob, notRob)
            left = dfs(root.left) 
            right = dfs(root.right)
            rob = root.val + left[1] + right[1]
            notRob = max(left) + max(right)
            return (rob, notRob)
        
        return max(dfs(root))

                
        