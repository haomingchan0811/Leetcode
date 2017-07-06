class Solution(object):
    
    # word level split and reverse: O(N) time & space
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        words = s.split()
        i, j = 0, len(words)-1
        while i <= j:
            words[i], words[j] = words[j], words[i]
            i, j = i+1, j-1
        return ' '.join(words)
    
    # Pythonic: split and reverse: O(N) time & space
    def reverseWords(self, s):
        return ' '.join(s.split()[::-1])
    
    # double reverse: O(N) time & space
    def reverseWords(self, s):
        s, i = s[::-1], 0
        w, words = '', []
        while i < len(s):
            while i < len(s) and s[i] != ' ': w, i = w+s[i], i+1
            if w != '':    # bug: w may be empty
                words.append(w[::-1])
                w = ''
            while i < len(s) and s[i] == ' ': i += 1    # bug: multiple spaces
        return ' '.join(words)
    
  
        