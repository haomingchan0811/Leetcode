class Solution(object):
    
    # brute force: O(N) time, O(1) space
    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        cnt_a = 0
        for i in xrange(len(s)):
            if s[i] == 'A': cnt_a += 1
            if cnt_a > 1 or (i < len(s)-2 and s[i:i+3] == 'LLL'): 
                return False
        return cnt_a <= 1
    
    # pythonic: O(N) time, O(1) space
    def checkRecord(self, s):
        cnt = len([1 for c in s if c == 'A'])
        return cnt <= 1 and ('LLL' not in s)
            
    # Regex 