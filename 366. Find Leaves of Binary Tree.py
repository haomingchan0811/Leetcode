# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # dfs, O(N) time, O(1) space
    def findLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ret = []
        def dfs(root, ret):
            if root == None:
                return -1
            depth = max(dfs(root.left, ret), dfs(root.right, ret)) + 1
            if len(ret) == depth:
                ret.append([root.val])
            else:
                ret[depth].append(root.val)
            return depth
        depth = dfs(root, ret)
        return ret
        
            
            
        