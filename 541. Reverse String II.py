class Solution(object):
    
    # Naive: O(N) time & space, 41.08%, ok
    def reverseStr(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        ret = ""
        i = 0
        while i + 2 * k <= len(s):
            reverse = s[i+k-1: : -1] if i == 0 else s[i+k-1: i-1: -1]
            ret += reverse + s[i+k: i+2*k]
            i += 2 * k
        if i < len(s):
            ret += (s[i+k-1: : -1] if i == 0 else s[i+k-1: i-1: -1]) + s[i+k:]
        return ret
        
    # List and reverse: O(N) time & space, 71.13%, ok
    def reverseStr(self, s, k):
        s = list(s)
        for i in xrange(0, len(s), 2*k):
            s[i:i+k] = reversed(s[i:i+k])
        return "".join(s)
        