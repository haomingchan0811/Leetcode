class Solution(object):
    
    # iterative brute force: O(2^(k+1)) time & space
    def findContestMatch(self, n):
        """
        :type n: int
        :rtype: str
        """
        match = [str(i) for i in xrange(1, n + 1)]
        while len(match) > 1:
            match = ['(%s,%s)' % (match[i], match[-1-i]) for i in xrange(len(match) / 2)]
        return match[0]
    
    # recursive brute force: O(2^(k+1)) time & space
    def findContestMatch(self, n):
        def helper(match):
            if len(match) == 1:
                return match[0]
            nextMatch = []
            for i in xrange(len(match) / 2):
                nextMatch.append('(%s,%s)' % (match[i], match[-1-i]))
            return helper(nextMatch)
        
        match = [str(i) for i in xrange(1, n + 1)]
        return helper(match)
            
        
        