class Solution:
    # @param s, a list of 1 length strings, e.g., s = ['h','e','l','l','o']
    # @return nothing
    
    # # WRONG: s can't be changed due to sys
    # # save words and reverse: O(N) time & space
    # def reverseWords(self, s):
    #     words, word = '', ''
    #     for c in s:
    #         if c == ' ':
    #             words = word + ' ' + words
    #             word = ''
    #         else:
    #             word += c
    #     if word != ' ':
    #         words = word + ' ' + words
    #     s = list(words[:-1])
    
    # double reverse: O(N) time, O(1) space
    def reverseWords(self, s):
        def rev(i, j):
            while i < j:
                s[i], s[j] = s[j], s[i]
                i, j = i + 1, j - 1
            
        rev(0, len(s) - 1)
        start, end = 0, 0
        while end < len(s):
            while end < len(s) and s[end] != ' ':
                end += 1
            rev(start, end - 1)
            start = end + 1
            end += 1
        if start < len(s):
            rev(start, len(s) - 1)

    # pythonic double reverse: O(N) time, O(1) space
    def reverseWords(self, s):
        s.reverse()
        start = 0
        for i in xrange(len(s)):
            if s[i] == ' ':
                s[start:i] = reversed(s[start:i])
                start = i + 1
        s[start:] = reversed(s[start:])
     
            
                
            
        
        
        