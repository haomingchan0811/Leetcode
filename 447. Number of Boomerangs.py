class Solution(object):
    
    def squareDist(self, p1, p2):
        return sum(map(lambda x: (x[0] - x[1]) ** 2, zip(p1, p2)))
    
    # # brute force: O(N3) time, O(1) space, TLE
    # def numberOfBoomerangs(self, points):
    #     """
    #     :type points: List[List[int]]
    #     :rtype: int
    #     """
    #     ret = 0
    #     for num1 in points:
    #         for num2 in points:
    #             if num1 != num2:
    #                 dist = self.squareDist(num1, num2)
    #                 for target in points:
    #                     if target not in [num1, num2] and dist == self.squareDist(num2, target):
    #                         ret += 1
    #     return ret
     
    # !! hash map: O(N2) time, O(N) space
    def numberOfBoomerangs(self, points):
        ret = 0
        for p1 in points:
            dist = {}
            for p2 in points:
                d = self.squareDist(p1, p2)
                dist[d] = dist.get(d, 0) + 1
            for d, cnt in dist.items():    # key point! for each point, count the points has the same distance
                ret += cnt * (cnt - 1)
        return ret
        