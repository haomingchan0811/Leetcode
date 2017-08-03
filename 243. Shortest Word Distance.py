class Solution(object):
    
    # brute force: O(N2) time, O(1) space
    def shortestDistance(self, words, word1, word2):
        """
        :type words: List[str]
        :type word1: str
        :type word2: str
        :rtype: int
        """
        ret = float('inf')
        for i in xrange(len(words)):
            if words[i] == word1:
                for j in xrange(len(words)):
                    if words[j] == word2:
                        ret = min(ret, abs(j - i))
        return ret
    
    # one pass: O(N) time, O(1) space
    def shortestDistance(self, words, word1, word2):
        index1, index2, ret = -1, -1, float('inf')
        for i, word in enumerate(words):
            if word == word1:
                index1 = i
            if word == word2:
                index2 = i
            if index1 != -1 and index2 != -1:
                ret = min(abs(index1 - index2), ret)
        return ret
        