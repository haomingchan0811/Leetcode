# Definition for a  binary tree node
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator(object):
    
    # stack: avg O(1) time, O(h) space
    # stack records all the left-braches nodes, when next() called, insert all left-brached nodes of poped 'node' from stack if 'node' has a right branch  
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.stack = []
        while root:
            self.stack.append(root)
            root = root.left

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.stack
        
    def next(self):
        """
        :rtype: int
        """
        node = self.stack.pop()
        curr = node.right
        while curr:
            self.stack.append(curr)
            curr = curr.left
        return node.val
        

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())