class Solution(object):
    def reverseString(s):
        if len(s) == 0:
            return s
        answer = ""
        iterator = len(s) - 1
        for i in range(len(s)):
            answer += s[iterator]
            iterator -= 1
        return answer