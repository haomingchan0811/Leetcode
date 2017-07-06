class Solution(object):
    
    # brute force: O(N) time, O(1) space, TLE
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        sum, i = 0, 1
        while i < num:
            sum += i if num % i == 0 else 0
            i += 1
        return sum == num
        
    # better brute force: O(sqrt(N)) time, O(1) space, TLE
    def checkPerfectNumber(self, num):
        if num == 1: return False
        sum, i = 1, 2
        while i ** 2 <= num:
            if num % i == 0:
                sum += (num / i) + i
            i += 1
        return sum == num
            