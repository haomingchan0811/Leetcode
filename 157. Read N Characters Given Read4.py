# The read4 API is already defined for you.
# @param buf, a list of characters
# @return an integer
# def read4(buf):

class Solution(object):   
    # buffer are already pre-located
    def read(self, buf, n):
        """
        :type buf: Destination buffer (List[str])
        :type n: Maximum number of characters to read (int)
        :rtype: The number of characters read (int)
        """
        total = 0
        while total < n:
            temp = ["" for i in range(4)]
            k = read4(temp)
            # print n, k, buf
            if k < 4 or n - total <= 4:
                buf[total: total + min(k, n - total)] = temp
                return total + min(k, n - total)
            buf[total: total + 4] = temp
            total += 4
        return 0
            
        