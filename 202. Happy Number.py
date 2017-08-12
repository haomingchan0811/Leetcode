class Solution(object):
    def cal(self, num):
        temp = 0
        while num:
            temp += (num % 10) ** 2
            num /= 10
        return temp
    
    # brute force: O(?) time, O(?) space
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        prev = []
        while n != 1:
            if n in prev:
                return False
            prev.append(n)
            n = self.cal(n)
        return True
    
    # !! slow and fast pointer: O(?) time, O(1) space
    def isHappy(self, n):
        x, y = n, n
        while x != 1:
            x = self.cal(x)
            if x == 1:
                return True     # bug: missing check
            y = self.cal(self.cal(y))
            if x == y:
                return False
            n = x
        return True
        
        