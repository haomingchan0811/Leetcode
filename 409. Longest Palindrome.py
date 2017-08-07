class Solution(object):
    
    # hash table: O(N) time & space
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        count, ret = {}, 0
        for c in s:
            count[c] = count.get(c, 0) + 1
        hasOdd = False
        for cnt in count.values():
            if cnt % 2 != 0:
                hasOdd = True
            ret += cnt / 2 * 2  # odd can contribute E.g: 3 can contribute 2
        return ret + (1 if hasOdd else 0)
        