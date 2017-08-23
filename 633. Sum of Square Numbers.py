import math
class Solution(object):
    
    # square root: O(log^2(c)) time (sqrt(N) takes logN time), O(1) space
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        for i in xrange(int(math.ceil(math.sqrt(c)))):   # bug: should be ceil
            temp = math.sqrt(c - i ** 2)
            if int(temp) == temp:   
                return True
        return True if c == 0 else False   # corner case: c = 0
    
    # square root: O(sqrt(c)*log(c)) time, O(1) space
    def judgeSquareSum(self, c):
        i = 0
        while i ** 2 <= c:  
            temp = math.sqrt(c - i ** 2)
            if int(temp) == temp:   
                return True
            i += 1
        return False   
        