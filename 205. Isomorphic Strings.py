class Solution(object):
    
    # hash map: O(n) time & space
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        s2t, t2s = {}, {}
        if len(s) != len(t):
            return False
        for c1, c2 in zip(s, t):
            if (c1 in s2t and s2t[c1] != c2) or (c2 in t2s and t2s[c2] != c1):
                return False
            s2t[c1], t2s[c2] = c2, c1
        return True
    
    # hash map: O(n) time, O(1) space
    def isIsomorphic(self, s, t):
        s2t, t2s = [-1 for i in range(256)], [-1 for i in range(256)]
        if len(s) != len(t):
            return False
        for i, (c1, c2) in enumerate(zip(s, t)):
            if s2t[ord(c1)] != t2s[ord(c2)]:
                return False
            s2t[ord(c1)] = t2s[ord(c2)] = i
        return True
        