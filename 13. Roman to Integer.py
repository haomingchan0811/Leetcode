class Solution(object):
    
    # hash table: O(N) time, O(1) space
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        roman = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        ret = 0
        for i in xrange(len(s)-1):
            curr = roman[s[i]]
            if curr < roman[s[i+1]]:
                ret -= curr
            else:
                ret += curr
        return ret + roman[s[-1]]
        