class Solution(object):
    
    # hash set, find reflection line: O(N) time & space
    def isReflected(self, points):
        pts = set()
        maxX, minX = float('-inf'), float('inf')
        for point in points:
            maxX = max(maxX, point[0])
            minX = min(minX, point[0])
            pts.add(tuple(point))
        mid = float(maxX + minX) / 2
        for point in points:
            x = 2 * mid - point[0]
            y = point[1]
            if (x, y) not in pts:
                return False
        return True
        