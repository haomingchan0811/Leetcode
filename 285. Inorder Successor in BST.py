# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # inoder dfs: O(N) time, O(1) space
    def inorderSuccessor(self, root, p):
        """
        :type root: TreeNode
        :type p: TreeNode
        :rtype: TreeNode
        """
        def dfs(root, p):
            if root:
                node = dfs(root.left, p)
                if node:
                    return node
                elif self.prev == p:
                    return root
                self.prev = root
                node = dfs(root.right, p)
                return node
            return None
        
        self.prev = None
        return dfs(root, p)

    # !! utilize bst: O(h) time, O(1) space
    def inorderSuccessor(self, root, p):
        succ = None
        while root:
            if root.val > p.val:
                succ = root
                root = root.left
            else:
                root = root.right      
        return succ
        