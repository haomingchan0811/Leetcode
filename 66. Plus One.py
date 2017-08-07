class Solution(object):
    
    # brute force: O(N) time, O(1) space
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        carry = 1
        for i in xrange(len(digits) - 1, -1, -1):
            temp = carry + digits[i]
            digits[i] = temp % 10
            carry = temp / 10
            if carry == 0:
                return digits
        return [1] + digits
    
    # better brute force: O(N) time, O(1) space
    def plusOne(self, digits):
        for i in xrange(len(digits) - 1, -1, -1):
            if digits[i] == 9:
                digits[i] = 0
            else:
                digits[i] += 1
                return digits
        return [1] + digits
                
        
        