# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class Solution(object):
    
    # dfs, find maxDepth and add: O(2N) time, O(1) space
    def depthSumInverse(self, nestedList):
        """
        :type nestedList: List[NestedInteger]
        :rtype: int
        """
        def getDepth(subList, depth):
            maxDepth = depth
            for elem in subList:
                if not elem.isInteger():
                    maxDepth = max(maxDepth, getDepth(elem.getList(), depth + 1))
            return maxDepth
                
        maxDepth = getDepth(nestedList, 1)
        self.ret = 0
        self.helper(nestedList, maxDepth)
        return self.ret
    
    def helper(self, subList, scalar):
        for elem in subList:
            if elem.isInteger():
                self.ret += elem.getInteger() * scalar
            else:
                self.helper(elem.getList(), scalar - 1)
                
    # dfs, flatten list: O(N) time, O(N) space
    def depthSumInverse(self, nestedList):
        def dfs(subList, depth, flatList, maxDepth):
            for elem in subList:
                if elem.isInteger():
                    flatList.append((elem.getInteger(), depth))
                else:
                    d = dfs(elem.getList(), depth + 1, flatList, depth + 1)
                    maxDepth = max(maxDepth, d)
            return maxDepth
        
        flatList, ret = [], 0
        maxDepth = dfs(nestedList, 1, flatList, 1)
        for (num, depth) in flatList:
            ret += num * (maxDepth - depth + 1)
        return ret

    # dfs, double the sum when go deeper: O(N) time, O(N) space
    def depthSumInverse(self, nestedList):
        ret, unweighted = 0, 0      # bug: add var 'unweighted' to keep track of all indiviuals
        while nestedList:
            unwrap = []
            print unwrap, ret
            for elem in nestedList:
                if elem.isInteger():
                    unweighted += elem.getInteger()   # bug: keep unweighted and weighted apart
                else:
                    unwrap.extend(elem.getList())
            nestedList = unwrap
            ret += unweighted
        return ret
    
   

   
        
        