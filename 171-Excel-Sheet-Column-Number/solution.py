class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans = 0
        count = 0
        for i in range(len(s) - 1, -1, -1):
            ans += (ord(s[i]) - ord('A') + 1) * pow(26.0, count)
            count += 1
        return int(ans)