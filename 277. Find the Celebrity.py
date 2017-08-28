# The knows API is already defined for you.
# @param a, person a
# @param b, person b
# @return a boolean, whether a knows b
# def knows(a, b):

class Solution(object):
    
    # two pass: O(N) time, O(1) space
    def findCelebrity(self, n):
        """
        :type n: int
        :rtype: int
        """
        ret = 0
        for i in xrange(1, n):
            if knows(ret, i):
                ret = i
        for i in xrange(n):
            if i != ret and (knows(ret, i) or not knows(i, ret)):
                return -1
        return ret
                
        