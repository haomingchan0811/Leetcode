class Solution(object):
    
    # brute force: O(2^N) time & space, TLE
    def findLongestChain(self, pairs):
        """
        :type pairs: List[List[int]]
        :rtype: int
        """
        def dfs(pairs, index, curr):
            if index == len(pairs):
                self.ret = max(self.ret, curr[0])
            else:
                for i in xrange(index, len(pairs)):
                    if pairs[i][0] > curr[1]:
                        dfs(pairs, i + 1, (curr[0] + 1, pairs[i][1]))
        self.ret = 0
        pairs = sorted(pairs, key = lambda x: x[0])
        dfs(pairs, 0, (0, float('-inf')))
        return self.ret
    
    # dynamic programming: O(NlogN) time, O(1) space
    def findLongestChain(self, pairs):
        if len(pairs) == 0:
            return 0
        pairs = sorted(pairs, key = lambda x: x[1])
        prev, ret = pairs[0][1], 1
        for s, e in pairs:
            if s > prev:
                prev = e
                ret += 1
        return ret