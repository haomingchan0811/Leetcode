class Solution(object):
    
    # bit manipulation / iterative: O(log_27N) time, O(1) space
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        ret = ''
        while n:
            num = n % 26 if n % 26 else 26
            ret = chr(ord('A') - 1 + num) + ret
            n = n / 26 - 1 if num == 26 else n / 26   # bug: 因为这里的base26没有余数0，整除26的case要特殊处理
        return ret
        
    # recursive: O(log_27N) time, O(1) space
    def convertToTitle(self, n):
        if n == 0: return ''
        num = n % 26 if n % 26 else 26
        n = n / 26 - 1 if num == 26 else n / 26
        return self.convertToTitle(n) + chr(ord('A') - 1 + num) 
    
    # more compact: O(log_27N) time, O(1) space
    def convertToTitle(self, n):
        ret = ''
        while n:
            num, n = (n - 1) % 26, (n - 1) / 26
            ret = chr(ord('A') + num) + ret
        return ret