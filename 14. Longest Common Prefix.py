class Solution(object):
    
    # N Pointer-vertical scan: O(N*minLen(word)) time, O(N) space
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0: return ''
        prefix, pts = '', 0
        minLen = min(map(lambda x: len(x), strs))
        while pts < minLen:
            letters = map(lambda x: x[pts], strs)
            if False in map(lambda x: x == letters[0], letters):
                return prefix
            else:
                prefix += letters[0]
                pts += 1
        return prefix
    
    # vertical scan: O(N*minLen(word)) time, O(1) space
    def longestCommonPrefix(self, strs):
        if len(strs) == 0: return ''
        prefix, pts = '', 0
        for i in xrange(len(strs[0])):
            char = strs[0][i]
            for j in xrange(1, len(strs)):
                if i == len(strs[j]) or strs[j][i] != char:
                    return strs[0][:i]
        return strs[0]
        