import heapq

# stack & heap & hashtable: O(NlogN) time, O(N) space
class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.count = {}
        self.heap = []
        self.stack = []
        

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.count[x] = self.count.get(x, 0) + 1
        heapq.heappush(self.heap, x)
        self.stack.append(x)
        
    def pop(self):
        """
        :rtype: void
        """
        if not self.stack:
            return
        self.count[self.stack[-1]] -= 1
        return self.stack.pop()
        
    def top(self):
        """
        :rtype: int
        """
        return self.stack[-1] if self.stack else None
        

    def getMin(self):
        """
        :rtype: int
        """
        while self.heap:
            if self.count[self.heap[0]] == 0:
                heapq.heappop(self.heap)
            else:
                return self.heap[0]
        return None

# two stack: O(N2) time, O(N) space 
class MinStack(object):

    def __init__(self):
        self.s1 = []
        self.s2 = []
        self.currMin = None

    def push(self, x):
        if self.currMin is None:
            self.currMin = self.getMin()
        if self.currMin is None or self.currMin > x:
            self.currMin = x
        self.s1.append(x)
        
    def pop(self):
        if not self.s1:
            self.currMin = None
            return
        curr = self.s1.pop()
        if curr == self.currMin:
            self.currMin = None
        return curr
        
    def top(self):
        return self.s1[-1]   

    def getMin(self):
        if self.currMin is None:
            while self.s1:
                curr = self.s1.pop()
                self.currMin = curr if self.currMin is None else min(self.currMin, curr)
                self.s2.append(curr)

            while self.s2:
                self.s1.append(self.s2.pop())
            
        return self.currMin

# one stack: O(N) time & space 
class MinStack(object):

    def __init__(self):
        self.stack = []

    def push(self, x):
        currMin = self.getMin()
        if currMin is None or currMin > x:
            currMin = x
        self.stack.append((x, currMin))
        
    def pop(self):
        self.stack.pop() if self.stack else None
        
    def top(self):
        return self.stack[-1][0] if self.stack else None   

    def getMin(self):
        return self.stack[-1][1] if self.stack else None



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()