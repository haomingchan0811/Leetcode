class Solution(object):
    
    # Brute force: O(mn) time, O(m+n) space
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        ret = 0
        for i in range(len(num1) - 1, -1, -1):
            n1 = ord(num1[i]) - ord('0')
            carry, curr = 0, 0
            for j in range(len(num2) - 1, -1, -1):
                n2 = ord(num2[j]) - ord('0')
                temp = carry + n1 * n2
                curr += (temp % 10) * (10 **(len(num2) - 1 - j))
                carry = temp / 10
            if carry != 0:
                curr += carry * (10 ** len(num2))
            ret += curr * (10 ** (len(num1) - 1 - i))
        return str(ret)
            
        