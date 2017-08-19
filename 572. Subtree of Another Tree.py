# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # recursive brute force: O(mn) time & space
    def isSubtree(self, s, t):
        """
        :type s: TreeNode
        :type t: TreeNode
        :rtype: bool
        """
        def isSameTree(t1, t2):
            if t1 and t2:
                if t1.val == t2.val:
                    return isSameTree(t1.left, t2.left) and isSameTree(t1.right, t2.right)
                else:
                    return False
            return [t1, t2].count(None) == 2
        
        queue = [s]
        for node in queue:
            if node.val == t.val and isSameTree(node, t):
                return True
            queue += filter(None, [node.left, node.right])
        return False
            
        