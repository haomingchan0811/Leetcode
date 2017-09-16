from collections import deque

class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue = deque()
        self.backup = deque()

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: void
        """
        self.queue.append(x)

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        last = None
        if self.queue:
            while self.queue:
                if last is not None:
                    self.backup.append(last)
                last = self.queue.popleft()
        else:
            while self.backup:
                if last is not None:
                    self.queue.append(last)
                last = self.backup.popleft()
        return last
        

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        last = None
        if self.queue:
            while self.queue:
                if last is not None:
                    self.backup.append(last)
                last = self.queue.popleft()
            self.backup.append(last)
        else:
            while self.backup:
                if last is not None:
                    self.queue.append(last)
                last = self.backup.popleft()
            self.queue.append(last)
        return last
        

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return not (len(self.queue) or len(self.backup))
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()