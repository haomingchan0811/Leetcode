class Solution(object):
    
    # sort: O(MNlogN) time, O(M) space
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        d = dict()
        for str in strs:
            root = tuple(sorted(str))
            d[root] = d.get(root, []) + [str]
            
        return d.values()    
        
