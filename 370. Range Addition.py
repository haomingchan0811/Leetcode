class Solution(object):
    
    # FAIL!! brute force: O(kN) time, no space, TLE
    def getModifiedArray(self, length, updates):
        """
        :type length: int
        :type updates: List[List[int]]
        :rtype: List[int]
        """
        ret = [0] * length
        for update in updates:
            for i in xrange(update[0], update[1]+1):
                ret[i] += update[2]
        return ret
        
    # update only headindex (+inc) & endindex + 1 (-inc)
    # finally compute accumulate sum for each element
    # O(k + N) time, O(1) space
    def getModifiedArray(self, length, updates):
        ret, accum = [0] * (length + 1), 0
        for update in updates:
            ret[update[0]] += update[2]
            ret[update[1]+1] -= update[2]
        for i in xrange(len(ret)):
            accum += ret[i] 
            ret[i] = accum
        return ret[:-1]
            