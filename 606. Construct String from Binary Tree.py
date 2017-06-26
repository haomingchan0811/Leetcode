# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # # dfs: O(N) time & space
    # def tree2str(self, t):
    #     """
    #     :type t: TreeNode
    #     :rtype: str
    #     """
    #     str = self.dfs(t) 
    #     return str if str == '' else str[1:-1]
        
    # def dfs(self, node):
    #     if node == None: return ''  # bug: should check null root
    #     if node.left == None and node.right == None: return '(%d)' % node.val
    #     if node.left == None: return '(%d()%s)' % (node.val, self.dfs(node.right))
    #     if node.right == None: return '(%d%s)' % (node.val, self.dfs(node.left))
    #     return '(%d%s%s)' % (node.val, self.dfs(node.left), self.dfs(node.right))
    
    # dfs, more elegant: O(N) time & space
    def tree2str(self, t):
        if t == None: return ''  # bug: should check null root
        if t.left == None and t.right == None: return '%d' % t.val
        if t.right == None: return '%d(%s)' % (t.val, self.tree2str(t.left))
        return '%d(%s)(%s)' % (t.val, self.tree2str(t.left), self.tree2str(t.right))