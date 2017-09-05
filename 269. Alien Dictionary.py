class Solution(object):
    
    # topological sort: O(E) time, O(N) space
    def alienOrder(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        def findCycle(i, adj):
            if self.gloVisited[i]:
                return False
            self.gloVisited[i] = self.locVisited[i] = True
            for neigh in adj[i]:
                if self.locVisited[neigh] or findCycle(neigh, adj):
                    return True
            self.ret += i
            self.locVisited[i] = False
            return False
           
        # if len(words) == 1:   # bug: corner case
        #     return words[0]
        adj = {}
        for word in words:
            for c in word:
                adj[c] = set()
        
        for k in xrange(1, len(words)):
            w1, w2, i = words[k - 1], words[k], 0
            while i < min(len(w1), len(w2)) and w1[i] == w2[i]:
                i += 1
            if i < min(len(w1), len(w2)):
                s, t = w1[i], w2[i]
                adj[t].add(s)
        
        self.ret, m = "", len(adj)
        self.gloVisited = {v: False for v in adj}
        self.locVisited = {v: False for v in adj}
        for v in adj:
            if not self.gloVisited[v] and findCycle(v, adj):
                return ""
        return self.ret
            
        