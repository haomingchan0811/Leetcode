class Solution(object):
    
#     # Actually WRONG! brute force: O(min(m,n)^2 * max(m,n)) time, O(min(m, n)) space
#     def findLUSlength(self, a, b):
#         """
#         :type a: str
#         :type b: str
#         :rtype: int
#         """
#         def isUncommon(substr, s):
#             j = 0
#             for i in xrange(len(substr)):
#                 while j < len(s) and s[j] != substr[i]:
#                     j += 1
#                 if j == len(s):
#                     return True                    
#             return False
        
#         if len(a) != len(b):
#             return max(len(a), len(b))
#         for length in xrange(len(a), 0, -1):
#             for start in xrange(len(a) - length + 1):
#                 substr = a[start: start + length]
#                 if isUncommon(substr, b):
#                     return length
#         return -1

    # !trick: O(1) time, no space
    def findLUSlength(self, a, b):
        return -1 if a == b else max(len(a), len(b))
                
        