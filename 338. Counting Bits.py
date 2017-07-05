class Solution(object):
    
    # brute force: O(N*sizeof(integer)) time, O(1) space 
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        ret, i = [], 0
        while i <= num:
            ret.append(bin(i)[2:].count('1'))
            i += 1
        return ret
    
    # math: O(N) time & space 
    def countBits(self, num):
        ret, i = [0], 1
        while i <= num:
            # 任何一个数的1 bit数量都是和前面一个数的bitwise与后1 bit的数量加一
            ret.append(ret[i & (i-1)] + 1)
            i += 1
        return ret
                