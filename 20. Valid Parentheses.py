class Solution(object):
    
    # stack: O(N) time & space
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack, paren = [], {")":"(", "}":"{", "]":"["}
        for c in s:
            if c in "({[":
                stack.append(c)
            else:
                if stack == [] or stack.pop() != paren[c]:   # bug: stack is empty
                    return False
        return len(stack) == 0
                
        