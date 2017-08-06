from collections import Counter
class Solution(object):
    
    # hash table: O(N) time & space
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        chars = Counter(s)
        for char in t:
            if not char in chars or chars[char] == 0:
                return False
            chars[char] -= 1
        for char in chars:
            if chars[char] != 0:
                return False
        return True
    
    # count: O(N) time & space
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False
        chars = [0 for i in xrange(26)]
        for c1, c2 in zip(s, t):
            chars[ord(c1) - ord('a')] += 1
            chars[ord(c2) - ord('a')] -= 1
        for count in chars:
            if count != 0:
                return False
        return True
    
    # sort: O(NlogN) time, O(N) space
    def isAnagram(self, s, t):
        s, t = list(s), list(t)
        s.sort()
        t.sort()
        return s == t
        
        