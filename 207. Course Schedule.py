class Solution(object):
    
    # topological sort: O(N) time, O(N) space
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        def findCycle(i, adjacent):
            if self.globalVisited[i]:
                return False
            self.globalVisited[i] = self.localVisited[i] = True
            for neigh in adjacent[i]:
                if self.localVisited[neigh] or findCycle(neigh, adjacent):
                    return True
            self.localVisited[i] = False  # back track 
            return False 
        
        if numCourses == 0 or len(prerequisites) == 0:
            return True
        self.globalVisited = [False for i in range(numCourses)]
        self.localVisited = [False for i in range(numCourses)]
        adjacent = {i:[] for i in range(numCourses)}
        for prev, curr in prerequisites:
            adjacent[prev] += [curr]
        for i in xrange(numCourses):
            if not self.globalVisited[i] and findCycle(i, adjacent):
                return False         
        return True
        