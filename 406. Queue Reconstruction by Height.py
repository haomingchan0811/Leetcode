class Solution(object):
    
    # !!! Greedy: O(NlogN) time, no space
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        # sort by higher height first, then lower count 
        people = sorted(people, key = lambda x: (-x[0], x[1]))
        ret = []
        for p in people:
            ret.insert(p[1], p)
        return ret