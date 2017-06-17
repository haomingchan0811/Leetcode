class Solution(object):
    
    # Two pointer: O(N) time & space
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        p1, p2 = 0, len(s)-1
        vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        s = [c for c in s]
        while p1 < p2:
            while p1 < len(s) and s[p1] not in vowels: p1 += 1
            while p2 >= 0 and s[p2] not in vowels: p2 -= 1
            if 0 <= p1 < p2 < len(s): 
                s[p1], s[p2] = s[p2], s[p1]
                p1, p2 = p1+1, p2-1
        return ''.join(s)
        
        # regular expression: 