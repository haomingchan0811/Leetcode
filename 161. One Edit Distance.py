class Solution(object):
    
    # !! brute force: O(N) time, O(1) space
    def isOneEditDistance(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        for i in xrange(min(len(s), len(t))):
            if s[i] != t[i]:
                if len(s) > len(t):
                    return s[i + 1:] == t[i:]
                elif len(s) == len(t):
                    return s[i + 1:] == t[i+1:]
                else:
                    return s[i:] == t[i+1:]
        return abs(len(s) - len(t)) == 1

    # !! pythonic: O(N) time, O(1) space
    def isOneEditDistance(self, s, t):
        for i in xrange(min(len(s), len(t))):
            if s[i] != t[i]:
                return s[i + (1 if len(s) >= len(t) else 0):] == t[i + (1 if len(s) <= len(t) else 0):]
        return abs(len(s) - len(t)) == 1
                
        