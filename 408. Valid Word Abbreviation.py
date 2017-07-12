class Solution(object):
    
    # Two pointers: O(N) time, O(1)
    def validWordAbbreviation(self, word, abbr):
        """
        :type word: str
        :type abbr: str
        :rtype: bool
        """
        if abbr == '': return False
        i, j = 0, 0
        while i < len(abbr):
            num = 0
            while i < len(abbr) and abbr[i].isdigit():
                if abbr[i] == '0' and num == 0:    # bug: leading zero is wrong 
                    return False
                num = num * 10 + int(abbr[i])
                i += 1
            j += num
            while i < len(abbr) and abbr[i].isalpha():
                if j >= len(word) or abbr[i] != word[j]:
                    return False
                i, j = i + 1, j + 1
        return j == len(word)
        
        
        