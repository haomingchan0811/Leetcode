class Solution(object):
    
    # Brute force: O(N) time & space, 56.6%
    def detectCapitalUse(self, word):
        """
        :type word: str
        :rtype: bool
        """
        num = len(filter(lambda x: ord(x) < ord('a'), list(word))) # can replace with isupper()
        return num == 0 or num == len(word) or (num == 1 and ord(word[0]) < ord('a'))
        
    # pythonic: O(N) time, no space, 70.41%
    def detectCapitalUse(self, word):
        return word.isupper() or word.islower() or word.istitle()
