from collections import deque
class MovingAverage(object):

    # queue: O(1) time, O(size) space
    def __init__(self, size):
        """
        Initialize your data structure here.
        :type size: int
        """
        self.queue = deque([])
        self.size = size
        self.sum = 0
                
    def next(self, val):
        """
        :type val: int
        :rtype: float
        """
        if len(self.queue) < self.size:
            self.sum += val
        else:
            self.sum += val - self.queue.popleft()
        self.queue.append(val)
        return self.sum * 1.0 / len(self.queue)

    # queue, pythonic: O(size) time, O(size) space
    def __init__(self, size):
        self.queue = deque(maxlen=size)
                
    def next(self, val):
        self.queue.append(val)
        return float(sum(self.queue)) / len(self.queue)
        


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)