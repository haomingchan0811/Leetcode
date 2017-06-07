class Solution(object):
        
    # swap with half pass: O(N) time & space, 29.80%, ok
    def reverseString(self, s):
        ret = list(s)
        i, j = 0, len(s) - 1
        while i < j:
           ret[i], ret[j] = ret[j], ret[i]
           i += 1
           j -= 1
        return "".join(ret)
        
    # STL: O(N) time & space, 49.26%, ok
    def reverseString(self, s):
        return s[::-1]