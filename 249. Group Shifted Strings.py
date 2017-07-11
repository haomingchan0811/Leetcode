from collections import defaultdict
class Solution(object):
    
    # combine by root: O(N* avg(wordLen)) time, O(N) space
    def groupStrings(self, strings):
        """
        :type strings: List[str]
        :rtype: List[List[str]]
        """
        group = defaultdict(list)  # better way to set default
        for s in strings:
            if s == '': group[''] = ''
            diff, root = ord(s[0]) - ord('a'), ''
            for c in s:
                if ord(c) - diff < ord('a'):
                    root += chr(ord(c) - diff + 26)
                else:
                    root += chr(ord(c) - diff)
            group[root].append(s)
        return group.values()