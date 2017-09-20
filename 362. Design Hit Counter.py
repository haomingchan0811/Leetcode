from collections import deque
class HitCounter(object):

    # queue: O(N) time, O(N) space
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue = deque()

    def hit(self, timestamp):
        """
        Record a hit.
        @param timestamp - The current timestamp (in seconds granularity).
        :type timestamp: int
        :rtype: void
        """
        self.queue.append(timestamp)

    def getHits(self, timestamp):
        """
        Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity).
        :type timestamp: int
        :rtype: int
        """
        while self.queue and self.queue[0] + 299 < timestamp:
            self.queue.popleft()
        return len(self.queue)

    # 300 bucket: O(N) time, O(1) space
    def __init__(self):
        self.times = {}    # record the real timestamp for the bucket 
        self.buckets = {}  # count of each timestamp

    def hit(self, timestamp):
        idx = timestamp % 300
        if idx not in self.times or self.times[idx] != timestamp:
            self.times[idx] = timestamp
            self.buckets[idx] = 1
        else:
            self.buckets[idx] += 1

    def getHits(self, timestamp):
        ret = 0
        for idx, count in self.buckets.items():
            if timestamp - self.times[idx] < 300:
                ret += count
        return ret
        

# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)