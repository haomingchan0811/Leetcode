class Solution(object):
    
    # iterative: O(log_7N) time, O(1) space
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0: return '0'       # bug: corner case
        ret, neg, num = '', num < 0, abs(num)
        for i in xrange(8, -1, -1):
            base = 7 ** i
            if base <= num: 
                ret += str(num / base)
                num = num % base
            else: 
                if len(ret) != 0: ret += '0'
        return '-%s' % ret if neg else ret
    
    # !!!! iterative: O(log_7N) time, O(1) space
    def convertToBase7(self, num):
        if num == 0: return '0'       # bug: corner case
        ret, neg, num = '', num < 0, abs(num)
        while num:
            ret = str(num % 7) + ret
            num /= 7
        return '-' + ret if neg else ret
    
    # !!! recursive: O(log_7N) time, O(1) space
    def convertToBase7(self, num):
        if num == 0: return '0'         # bug: corner case
        if num < 0: return '-' + self.convertToBase7(-num)
        if num < 7: return str(num)
        return self.convertToBase7(num / 7) + str(num % 7) 