class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        #ans = True
        #s = s.lowercase
        text = ''.join([char.lower() for char in s if char.isalnum()])
        return text == text[::-1]
        