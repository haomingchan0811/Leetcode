from math import sqrt
class Solution(object):
    
#     # binary search: O(logN*sqrt(N)) time, O(1) space, TLE
#     def constructRectangle(self, area):
#         """
#         :type area: int
#         :rtype: List[int]
#         """
#         def findSqrt(num):
#             low, high = 1, num
#             while low + 1 < high:
#                 mid = low + (high - low) / 2
#                 if mid * mid <= num:
#                     low = mid
#                 else:
#                     high = mid
#             if high ** 2 <= num:
#                 return high
#             return low
        
#         root = findSqrt(area)
#         for i in xrange(root, area + 1):
#             n = area / i
#             if float(area) / i == n:
#                 return [max(n, i), min(n, i)]

    # # pythonic, binary search: O(logN*sqrt(N)) time, O(1) space
    # def constructRectangle(self, area):
    #     root = sqrt(area)
    #     root = int(root) if root == int(root) else int(root) + 1
    #     for i in xrange(root, area + 1):
    #         n = area / i
    #         if float(area) / i == n:
    #             return [i, n]
    
    # pythonic binary search: O(logN * sqrt(N)) time, O(1) space
    def constructRectangle(self, area):
        root = int(sqrt(area))
        while root > 0: 
            if area % root == 0:
                return [area / root, root]
            root -= 1
                
        
        
        
                
        
        