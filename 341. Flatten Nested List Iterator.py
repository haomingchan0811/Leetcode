# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
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

class NestedIterator(object):

#     # Wrong!!!: only works for at most 2-layer nestedList, but nestedList can be more than 2 layers
#     def __init__(self, nestedList):
#         self.List = nestedList
#         self.idx = 0
#         self.inner_idx = 0

#     def next(self):
#         if not self.hasNext():
#             return None
#         elem = self.List[self.idx]
#         if elem.isInteger():
#             self.idx += 1
#             return elem.getInteger()
#         else:
#             vals = elem.getList()
#             ret = vals[self.inner_idx].getInteger()
#             self.inner_idx += 1
#             if self.inner_idx == len(vals):
#                 self.inner_idx = 0
#                 self.idx += 1
#             return ret

#     def hasNext(self):
#         return self.idx != len(self.List)

    # !!! stack,  deal with corner case [[]] 
    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self.stack = nestedList[::-1]  
        
    def next(self):
        """ :rtype: int """
        return self.stack.pop()
            
    def hasNext(self):   # deal with nested list here to avoid corner case of empty nestedInteger
        """ :rtype: bool """
        while self.stack:
            elem = self.stack[-1]
            if elem.isInteger():
                return True
            elem = self.stack.pop()   # is nested list
            self.stack += elem.getList()[::-1]
        return False
        

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())