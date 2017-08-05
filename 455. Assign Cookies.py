class Solution(object):
    
    # sort and greedy: O(nlogn + mlogm + max(m,n)) time, O(1) space
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        ret = 0
        g.sort()
        s.sort()
        i, j = len(g) - 1, len(s) - 1
        while i >= 0 and j >= 0:
            if s[j] >= g[i]:
                ret += 1
                i, j = i - 1, j - 1
            else:
                i -= 1
        return ret
        
        