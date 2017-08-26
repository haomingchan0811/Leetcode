class Solution(object):
    
    # recursive, hash table: O(N) time, O(1) space
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        lessThan20 = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        tens = ["", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        thousands = ["", "Thousand", "Million", "Billion"]
        
        def lessThanThousand(num):
            if num == 0:
                return ""
            elif num < 20:
                return lessThan20[num]
            elif num < 100:
                return tens[num / 10] + " " + lessThan20[num % 10]
            else:
                return lessThan20[num / 100] + " Hundred " + lessThanThousand(num % 100)
        
        if num == 0:
            return "Zero"
        ret, i = "", 0
        while num:
            if num % 1000:
                ret = lessThanThousand(num % 1000).rstrip() + " " + thousands[i] + " " + ret
            num /= 1000
            i += 1
        return ret.rstrip()
            
        
        