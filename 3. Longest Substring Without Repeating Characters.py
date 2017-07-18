from collections import Counter
class Solution(object):
    
    # # brute force: O(N3) time, O(N) space, TLE
    # def lengthOfLongestSubstring(self, s):
    #     """
    #     :type s: str
    #     :rtype: int
    #     """
    #     ret = 0
    #     for i in xrange(len(s)):
    #         for j in xrange(i, len(s)):
    #             cnt = Counter(s[i:j + 1])
    #             if len(filter(lambda x: x > 1, cnt.values())) == 0:
    #                 ret = max(ret, j - i + 1)
    #     return ret
    
    # hash table: store the latest index of each char
    # O(N) time, O(N) space
    def lengthOfLongestSubstring(self, s):
        ret, i = 0, 0
        pos = {}
        for j in xrange(len(s)):
            if s[j] in pos and pos[s[j]] >= i:   # bug: pos[s[j]] >= i
                ret = max(ret, j - i)
                i = pos[s[j]] + 1
            pos[s[j]] = j   # save lastest position
        ret = max(ret, len(s) - i)
        print '----'
        return ret
        