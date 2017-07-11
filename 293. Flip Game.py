class Solution(object):
    
    # brute force: O(N) time, O(1) space
    def generatePossibleNextMoves(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        ret = []
        for i in xrange(len(s)-1):
            if s[i] == s[i+1] == '+':
                ret.append(s[:i] + '--' +s[i+2:])
        return ret
        