class Solution(object):
    
    # brute force: O(?) Time, O(?) space
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        ret = '1'
        if n == 1: 
            return ret
        for i in xrange(1, n):
            temp, cnt = '', 1
            for j in xrange(1, len(ret)):
                if ret[j] == ret[j - 1]:
                    cnt += 1
                else:
                    temp += str(cnt) + str(ret[j - 1])
                    cnt = 1
            ret = temp + str(cnt) + str(ret[-1])
        return ret
                
        