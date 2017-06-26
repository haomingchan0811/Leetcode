from collections import Counter
class Solution(object):
    
    # # FAIL: # bug: 1. can have duplicate points 2. parallelogram
    # def validSquare(self, p1, p2, p3, p4):
    #     """
    #     :type p1: List[int]
    #     :type p2: List[int]
    #     :type p3: List[int]
    #     :type p4: List[int]
    #     :rtype: bool
    #     """
    #     def squareDist(x, y):   
    #         return (x[0] - y[0]) ** 2 + (x[1] - y[1]) ** 2
    #     if squareDist(p1, p2) == squareDist(p1, p3) and p2 != p3: 
    #         return squareDist(p1, p2) + squareDist(p1, p3) == squareDist(p2, p3) == squareDist(p1, p4)
    #     if squareDist(p2, p1) == squareDist(p2, p3) and p1 != p3: 
    #         return squareDist(p2, p1) + squareDist(p2, p3) == squareDist(p1, p3) == squareDist(p2, p4)
    #     if squareDist(p3, p1) == squareDist(p3, p2) and p1 != p2: 
    #         return squareDist(p3, p1) + squareDist(p3, p2) == squareDist(p1, p2) == squareDist(p3, p4)
    #     return False
    
    # count pair-wise distance, should have 4 equal sides and 2 equal diagonals 
    def validSquare(self, p1, p2, p3, p4):
        def squareDist(x, y):   
            return (x[0] - y[0]) ** 2 + (x[1] - y[1]) ** 2
        points, dists = [p1, p2, p3, p4], {}
        for i in xrange(4):
            for j in xrange(i+1, 4):
                dist = squareDist(points[i], points[j])
                dists[dist] = dists.get(dist, 0) + 1
        print dists
        return len(dists) == 2 and set(dists.values()) == {2, 4} # bug: list has order
        