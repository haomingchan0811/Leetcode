class Solution(object):
    
    # hash table: O(N) time & space
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = {}
        for char in s:
            count[char] = count.get(char, 0) + 1
        for i, char in enumerate(s):
            if count[char] == 1:
                return i
        return -1
    
    # hash table better traverse: if original string is too long
    # O(N) time & space
    def firstUniqChar(self, s):
        count = {}
        for i, char in enumerate(s):
            if char in count:
                count[char] = (count[char][0] + 1, i)
            else:
                count[char] = (1, i)
        ret = float('inf')
        for char, (cnt, index) in count.items():
            if cnt == 1:
                ret = min(ret, index)
        return -1 if ret == float('inf') else ret
                
        