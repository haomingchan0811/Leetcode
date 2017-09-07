class Solution(object):
    # brute force: O(mn) time, O(1) space
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if len(needle) > len(haystack):
            return -1
        if needle == '':
            return 0
        for i in xrange(len(haystack)):
            if needle == haystack[i:i+len(needle)]:
                return i
        return -1
                
        