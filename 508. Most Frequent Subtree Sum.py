# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    # dfs & hashmap: O(N) time & space
    def findFrequentTreeSum(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        def treeSum(node, cnt):
            if not node:
                return 0
            ret = treeSum(node.left, cnt) + treeSum(node.right, cnt) + node.val
            cnt[ret] = cnt.get(ret, 0) + 1
            return ret
            
        cnt = {}
        treeSum(root, cnt)
        maxCnt = -1
        for num, count in cnt.items():
            if count > maxCnt:
                maxCnt = count
        return [num for num in cnt if cnt[num] == maxCnt]
        
        