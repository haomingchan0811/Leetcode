class Solution(object):
    
    # Brute force: O(N) time, O(1) space
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        while num >= 10:
            temp = 0
            while num:
                temp += num % 10
                num /= 10
            num = temp
        return num
    
    # Math: O(1) time, no space
    def addDigits(self, num):
        if num == 0: return 0
        else: return 1 + (num - 1) % 9