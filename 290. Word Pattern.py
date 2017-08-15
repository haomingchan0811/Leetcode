class Solution(object):
    
    # hash table: O(N) time & space
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        str = str.split()
        if len(pattern) != len(str):
            return False
        p2s, s2p = {}, {}
        for p, s in zip(pattern, str):
            if p not in p2s and s not in s2p:
                p2s[p], s2p[s] = s, p
            elif p in p2s and p2s[p] == s and s in s2p and s2p[s] == p:
                continue 
            else:
                return False
        return True 
                
        
        