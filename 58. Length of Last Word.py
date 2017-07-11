class Solution(object):
    
    # brute force: O(N) time & space
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt = 0
        for i in xrange(len(s)-1, -1, -1):
            if s[i] != ' ':
                cnt += 1
            elif cnt > 0:
                return cnt
            else: continue
        return cnt
    
     # pythonic: O(N) time & space
    def lengthOfLastWord(self, s):
        return len(s.rstrip().split(' ')[-1])
        