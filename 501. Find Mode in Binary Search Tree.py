# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # recursive inorder traversal and count: O(N) time, O(N) space
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        def dfs(root):
            if root:
                self.count[root.val] = self.count.get(root.val, 0) + 1
                self.mode_cnt = max(self.mode_cnt, self.count[root.val])
                dfs(root.left)
                dfs(root.right)
                
        self.count, self.mode_cnt = {}, 0
        dfs(root)
        return [x for x in self.count if self.count[x] == self.mode_cnt]

    # iterative inorder traversal and count: O(N) time, O(N) space
    def findMode(self, root):
        if root is None:
            return []
        stack, count, mode = [root], {}, 0
        while stack:
            elem = stack.pop()
            if isinstance(elem, TreeNode):
                if elem.right:
                    stack.append(elem.right)
                stack.append(elem.val)
                if elem.left:
                    stack.append(elem.left)
            else:
                count[elem] = count.get(elem, 0) + 1
                mode = max(mode, count[elem])
            
        return [x for x in count if count[x] == mode]

    # !! two pass inorder traversal: O(N) time, O(1) space
    def findMode(self, root):
        def inorder(root):
            if root:
                inorder(root.left)
                if self.prev is None or self.prev == root.val:
                    self.count += 1
                else:
                    self.count = 1
                self.prev = root.val
                
                if self.count > self.maxCnt:
                    self.maxCnt = self.count
                    self.ret = [root.val]
                elif self.count == self.maxCnt:
                    self.ret.append(root.val)
                inorder(root.right)
                    
        self.count, self.maxCnt = 0, 0
        self.prev, self.ret = None, []
        inorder(root)
        return self.ret
        
        
        
        