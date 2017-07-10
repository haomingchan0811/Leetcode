from collections import Counter
class Solution(object):
    
    # hashtable: O(m+n) time, O(1) space
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        cnt = Counter(magazine)
        for letter in ransomNote:
            if letter not in cnt or cnt[letter] <= 0:
                return False
            cnt[letter] -= 1
        return True
        