class Solution(object):
    
    # brute force: O(len(s))time, O(1) space
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s: return 0
        ret, i = 0, 0
        for c in s[::-1]:
            ret += (ord(c) - ord('A') + 1) * (26 ** i)
            i += 1
        return ret
        
    # brute force pythonic: O(len(s))time, O(1) space
    def titleToNumber(self, s):
        return sum((ord(s[len(s)-i-1]) - ord('A') + 1) * (26 ** i) for i in xrange(len(s)))
        
    # brute force reduce: O(len(s))time, O(1) space
    def titleToNumber(self, s):
        return reduce(lambda x, y: x * 26 + y, [ord(c) - ord('A') + 1 for c in s])