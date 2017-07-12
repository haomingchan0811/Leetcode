class Solution(object):
    
    # !! brute force: O(N) time, O(1) space
    def isOneEditDistance(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) > len(t): s, t = t, s
        if s == t or len(t) - len(s) > 1: 
            return False

        i, sameLen = 0, len(s) == len(t)
        while i < len(s):
            if s[i] != t[i]:
                if i == 0:
                    if sameLen and s[1:] == t[1:]:
                        return True
                    return s == t[1:]
                elif i == len(s) - 1:
                    return sameLen or s[i] == t[i + 1:] 
                else:
                    if sameLen and s[i + 1:] == t[i + 1:]:
                        return True
                    return s[i:] == t[i + 1:]
            i += 1
        return len(t[i:]) == 1    # bug: check remaining string

    # !! pythonic: O(N) time, O(1) space
    def isOneEditDistance(self, s, t):
        for i in xrange(min(len(s), len(t))):
            if s[i] != t[i]:
                return s[i + (1 if len(s) >= len(t) else 0):] == t[i + (1 if len(s) <= len(t) else 0):]
        return abs(len(s) - len(t)) == 1
                
        