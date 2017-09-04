class Solution(object):
    
    # topological sort: O(N) time, O(N) space
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        def findCycle(i, adj):
            if self.gloVisited[i]:
                return False
            self.gloVisited[i] = self.locVisited[i] = True
            for neigh in adj[i]:
                if self.locVisited[neigh] or findCycle(neigh, adj):
                    return True
            self.ret.append(i)
            self.locVisited[i] = False
            return False
        
        if len(prerequisites) == 0:    # bug: can have empty prerequisites list
            return range(numCourses)
        self.gloVisited = [False for i in range(numCourses)]
        self.locVisited = [False for i in range(numCourses)]
        self.ret = []
        adj = {i:[] for i in range(numCourses)}
        for t, s in prerequisites:
            adj[t] += [s]
        
        for i in xrange(numCourses):
            if not self.gloVisited[i] and findCycle(i, adj):  # impossible to arrange due to cycle
                return []

        return self.ret
        