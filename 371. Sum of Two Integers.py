class Solution(object):
    
    # bit manipulation: O(max(m,n)) time, O(1) space
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        if abs(b) > abs(a): a, b = b, a
        a_pos, b_pos = bin(a)[0] != '-', bin(b)[0] != '-'
        sameSign, a, b = a_pos == b_pos, abs(a), abs(b)   # bug: negative num -> bin(-1) = '-0b1'
        bit_a, bit_b = bin(a)[2:], bin(b)[2:]       
        i, j, carry, ret = len(bit_a)-1, len(bit_b)-1, 0, ''
        
        while i >= 0 or j >= 0 or carry:
            x = int(bit_a[i]) if i >= 0 else 0
            y = int(bit_b[j]) if j >= 0 else 0
            ret = str(x ^ y ^ carry) + ret 
            if sameSign:
                carry = len(filter(lambda k: k == 1, [x, y, carry])) > 1 
            else:
                carry = (carry == 0 and x == 0 and y) or (carry and not (x and y == 0))
            i, j = i-1, j-1
        return int(ret, 2) * (1 if a_pos else -1)

    # bit manipulation: O(log(max(m,n))) time, O(1) space 
    # DIDN'T WORK WITH NEG + POS????
    def getSum(self, a, b):
        sumWithoutCarry = a
        while b != 0:
            sumWithoutCarry = a ^ b
            b = (a & b) << 1
            a = sumWithoutCarry
            print a, b
        return sumWithoutCarry
        