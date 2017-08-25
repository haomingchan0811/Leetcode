class Solution(object):
    
    # hash map: O(N) time, O(N) space
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        ret, dna = [], {}
        for i in xrange(10, len(s) + 1):
            if dna.get(s[i - 10: i], 0) == 1:
                ret.append(s[i - 10: i])
            dna[s[i - 10: i]] = dna.get(s[i - 10: i], 0) + 1
        return ret
        