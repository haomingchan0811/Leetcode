class Solution(object):
    
    # pythonic: O(N) time & space
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        words = s.split(' ')
        return len(filter(lambda x: x != '', words))
    
    # brute force: O(N) time & space
    def countSegments(self, s):
        i, cnt, word = 0, 0, ''
        while i < len(s):
            while i < len(s) and s[i] == ' ':
                i += 1
            while i < len(s) and s[i] != ' ':
                i, word = i + 1, word + s[i]
            if word != '':
                cnt, word = cnt + 1, ''
        return cnt
            
            
                
        
        