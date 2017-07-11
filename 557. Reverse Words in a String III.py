class Solution(object):
    
    # brute force: O(N*avglen(word)) time, O(N) space
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        def rev(word):
            i, j = 0, len(word) - 1
            while i < j:
                word[i], word[j] = word[j], word[i]
                i, j = i + 1, j - 1
            return ''.join(word)   
        
        curr, ret = [], ''
        for c in s:
            if c == ' ':
                ret += rev(curr) + ' '
                curr = []
            else:
                curr.append(c)
        if curr != []: ret += rev(curr)
        return ret

    # pythonic: O(N*avglen(word)) time, O(N) space
    def reverseWords(self, s):
        def rev(word):
            i, j = 0, len(word) - 1
            while i < j:
                word[i], word[j] = word[j], word[i]
                i, j = i + 1, j - 1
            return ''.join(word)   
        
        return ' '.join([rev(list(w)) for w in s.split(' ')])
        