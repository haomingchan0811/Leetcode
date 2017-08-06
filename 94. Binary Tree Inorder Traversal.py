# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # recursive dfs: O(N) time, O(h) space
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        def dfs(root, ret):
            if not root:
                return 
            dfs(root.left, ret)
            ret.append(root.val)
            dfs(root.right, ret)
        
        ret = []
        dfs(root, ret)
        return ret

    # iterative, stack: O(N) time, O(h) space
    def inorderTraversal(self, root):
        ret, stack = [], [root]
        while stack:
            elem = stack.pop()
            if elem:
                if isinstance(elem, TreeNode):
                    stack += [elem.right, elem.val, elem.left]
                else:
                    ret.append(elem)
        return ret
                