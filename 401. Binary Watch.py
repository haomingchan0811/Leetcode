class Solution(object):
    
    # back tracking: O(2^10) time & space
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        def dfs(hour, minute, index, n):
            if hour <= 11 and minute <= 59 and index <= len(self.times):
                if n == 0:
                    self.ret.append(str(hour) + ':' + ('0' if minute < 10 else '') + str(minute)) 
                else:
                    for i in xrange(index, len(self.times)):
                        if i < 4:  # hour
                            dfs(hour + self.times[i], minute, i + 1, n - 1)
                        else:
                            dfs(hour, minute + self.times[i], i + 1, n - 1)
        
        self.ret = []
        self.times = [8, 4, 2, 1, 32, 16, 8, 4, 2, 1]
        dfs(0, 0, 0, num)
        return self.ret

    # !! bit manipulation: O(60*12) time, O(1) space
    def readBinaryWatch(self, num):
        ret = []
        for i in xrange(12):
            for j in xrange(60):
                if bin(i).count('1') + bin(j).count('1') == num:
                    ret.append('%d:%02d' % (i, j))
        return ret
        
        