class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        test = []
        for i in s:
            if i.isalnum():
                test.append(i.lower())
        return str(test) == str(test[::-1])
        