class Solution(object):
    
    # Brute force: O(mn) time, O(m) space, 68.37%
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        letters = ['qwertyuiop', 'asdfghjkl', 'zxcvbnm']
        rows, ret = dict(), list()
        for index, letter in enumerate(letters):
            rows.update({c: index for c in letter})

        for word in words:
            wordLower = word.lower()
            rowNum, idx = [rows[c] for c in wordLower], rows[wordLower[0]]
            same = True
            for c in wordLower:
                if not rows[c] == idx:
                    same = False
                    break
            if same: ret.append(word)
        return ret
        
    # Set: O(mn) time, O(m) space, 13.44%
    def findWords(self, words):
        lines, ret = [set('qwertyuiop'), set('asdfghjkl'), set('zxcvbnm')], []
        for word in words:
            w = set(word.lower())
            for line in lines:
                if w.issubset(line):
                    ret.append(word)
        return ret

    # Set: O(mn) time, O(m) space, 52.56%
    def findWords(self, words):
        line1, line2, line3, ret = set('qwertyuiop'), set('asdfghjkl'), set('zxcvbnm'), []
        for word in words:
            w = set(word.lower())
            if line1 & w == w or line2 & w == w or line3 & w == w:
                ret.append(word)
        return ret
