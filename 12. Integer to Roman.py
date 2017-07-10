class Solution(object):
    
    # hash table: O(1) time & space
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        ret, counter = '', [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        roman = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
        for i in xrange(len(counter)):
            if num / counter[i]:
                ret += roman[i] * (num / counter[i])
                num %= counter[i]
        return ret
            
        
        