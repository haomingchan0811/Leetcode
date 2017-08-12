class Solution(object):
    
    # brute force decomposition: O(log5 + log3 + log2) time, O(1) space
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0:  # boundry check
            return False
        if num & (num - 1) == 0:  # power of 2
            return True
        factors = [2, 3, 5]
        while num != 1:
            decompose = False
            for f in factors:
                if num % f == 0:
                    decompose = True
                    num /= f
            if not decompose:
                return False
        return True
    
    # faster brute force decomposition: O(log5 + log3 + log2) time, O(1) space
    def isUgly(self, num):
        if num <= 0:  # boundry check
            return False
        for f in [5, 3]:
            while num != 1 and num % f == 0:
                num /= f
        if num == 1:
            return True
        return num & (num - 1) == 0 # power of 2
    
    # pythonic brute force decomposition: O(log5 + log3 + log2) time, O(1) space
    def isUgly(self, num):
        if num <= 0:  # boundry check
            return False
        for f in [5, 3, 2]:
            while num % f == 0:
                num /= f
        return num == 1
     