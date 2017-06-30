class Solution(object):
    
    # brute force recursion: O(N) time & space
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        ret, i = '', 0
        while i < len(s):
            if not s[i].isdigit():
                while i < len(s) and not s[i].isdigit():
                    ret, i = ret + s[i], i + 1
            else:
                num = ''
                while s[i].isdigit(): 
                    num, i = num + s[i], i + 1   # bug: num can be multiple digits
                substr, num, i, left_brackets = s[i+1], int(num), i+2, 1
                while left_brackets != 0:
                    substr += s[i]
                    if s[i] == '[': left_brackets += 1
                    if s[i] == ']': left_brackets -= 1
                    i += 1
                ret += num * self.decodeString(substr[:-1])
        return ret 
    
    # stack !!!!: O(N) time & space
    def decodeString(self, s):
        stack, num = [["", 1]], ''
        for c in s:
            if c.isdigit():
                num += c
            elif c == '[': 
                stack.append(["", int(num)])
                num = ""
            elif c == ']': 
                substr, k = stack.pop()
                stack[-1][0] += substr * k
            else:
                stack[-1][0] += c
            print stack
        return stack[0][0]
        