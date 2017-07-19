class Solution(object):
    
    # assume pattern and validate: O(N) time, O(N) space
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        for patternLen in xrange(len(s) / 2, 0, -1):
            cnt = len(s) / patternLen
            if cnt * patternLen == len(s) and s[:patternLen] * cnt == s:
                return True
        return False
        