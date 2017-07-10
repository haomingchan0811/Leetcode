class Solution(object):
    
    # brute force: O(mn) time, O(1) space
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if needle == "": return 0  # corner case
        for i in xrange(len(haystack) - len(needle) + 1):
            index, found = i, True
            for j in xrange(len(needle)):
                if haystack[i+j] != needle[j]:
                    found = False
                    break
            if found: return i
        return -1
        