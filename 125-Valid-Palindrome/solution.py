class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        test = ''
        for i in s:
            if i.isalnum():
                test += i.lower()
        return test == test[::-1]
        