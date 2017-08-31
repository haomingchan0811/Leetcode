class Solution(object):
    # # backtracking with two pointers: O(2^N) time, O(1) space, TLE
    # def isInterleave(self, s1, s2, s3):
    #     """
    #     :type s1: str
    #     :type s2: str
    #     :type s3: str
    #     :rtype: bool
    #     """
    #     def helper(s1, i, s2, j, s3, k):
    #         if i == len(s1) and j == len(s2) and k == len(s3):
    #             return True
    #         if j < len(s2) and s2[j] == s3[k] and helper(s1, i, s2, j + 1, s3, k + 1):
    #             return True
    #         if i < len(s1) and s1[i] == s3[k] and helper(s1, i + 1, s2, j, s3, k + 1):  
    #             return True
    #         return False
    #     if len(s1) + len(s2) != len(s3):
    #         return False
    #     return helper(s1, 0, s2, 0, s3, 0)
    
    # backtracking with two pointers and memorization: O(M+N) time, O(N2) space, TLE
    def isInterleave(self, s1, s2, s3):
        def helper(s1, i, s2, j, s3, k):
            if i == len(s1) and j == len(s2) and k == len(s3):
                return True
            if j < len(s2) and s2[j] == s3[k]:
                if (i, j, k) in self.memo:
                    return self.memo[(i, j, k)]
                if helper(s1, i, s2, j + 1, s3, k + 1):
                    self.memo[(i, j, k)] = True
                    return True
            if i < len(s1) and s1[i] == s3[k]:
                if (i, j, k) in self.memo:
                    return self.memo[(i, j, k)]
                if helper(s1, i + 1, s2, j, s3, k + 1): 
                    self.memo[(i, j, k)] = True
                    return True
            self.memo[(i, j, k)] = False
            return False
        
        if len(s1) + len(s2) != len(s3):
            return False
        self.memo = {}
        return helper(s1, 0, s2, 0, s3, 0)

                