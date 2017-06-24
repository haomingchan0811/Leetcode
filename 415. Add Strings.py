class Solution(object):
    
    # brute force: O(N) time & space
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        ret, carry, i, j = '', 0, len(num1)-1, len(num2)-1
        while carry or i >= 0 or j >= 0:
            x = int(num1[i]) if i >= 0 else 0
            y = int(num2[j]) if j >= 0 else 0
            ret = str((x + y + carry) % 10) + ret
            carry = (x + y + carry) / 10
            i, j = i-1, j-1
        return ret

        