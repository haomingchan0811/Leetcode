class Solution(object):
    
    # Hashtable: O(m) time, O(m) space, 45.48%
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        count = {}
        for c in s:
            count[c] = count.get(c, 0) + 1
        for c in t:
            count[c] = count.get(c, 0) - 1
            if count[c] < 0:
                return c
      
    # Bit Manipulation: O(m) time, O(1) space, 57.66%
    def findTheDifference(self, s, t):
        # return chr(reduce(lambda x, y: x ^ y, map(lambda x: ord(x), s + t)))
        return chr(reduce(operator.xor, map(ord, s + t)))  # 88.31%