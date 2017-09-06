class Solution(object):
    
    # brute force: O(N) time & space 
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        carry, ret, i, j = '0', '', len(a)-1, len(b)-1
        while carry == '1' or i >= 0 or j >= 0:
            x = a[i] if i >= 0 else '0'
            y = b[j] if j >= 0 else '0'
            cnt = (x + y + carry).count('1')
            ret = str(cnt % 2) + ret
            carry = '1' if cnt > 1 else '0'
            i, j = i-1, j-1
        return ret

    def addBinary(self, a, b):
        if a == "":
            return b
        if b == "":
            return a
        i, j, carry = len(a) - 1, len(b) - 1, 0
        ret = ""
        while carry or i >= 0 or j >= 0:
            x = 1 if i >= 0 and a[i] == '1' else 0
            y = 1 if j >= 0 and b[j] == '1' else 0
            sums = x + y + carry
            ret += str(sums % 2)
            carry = sums / 2
            i, j = i - 1, j - 1
        return ret[::-1]
        
        
        