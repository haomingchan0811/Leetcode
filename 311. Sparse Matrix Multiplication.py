class Solution(object):
    
    # brute force: O(mnk) time, O(1) space, TLE
    def multiply(self, A, B):
        """
        :type A: List[List[int]]
        :type B: List[List[int]]
        :rtype: List[List[int]]
        """
        m, n, k = len(A), len(A[0]), len(B[0])
        ret = [[0 for j in range(k)] for i in range(m)]
        for row in xrange(m):
            for col in xrange(k):
                for i in xrange(n):
                    ret[row][col] += A[row][i] * B[i][col]
        return ret
    
    # hash table: O(mn + nk) time, O(mn) space
    def multiply(self, A, B):
        m, n, k = len(A), len(A[0]), len(B[0])
        ret = [[0 for j in range(k)] for i in range(m)]
        nums = {}
        for row in xrange(m):
            for col in xrange(n):
                if A[row][col] != 0:
                    if col in nums:
                        nums[col][row] = A[row][col]
                    else:
                        nums[col] = {row: A[row][col]}
        print nums
        for row in xrange(n):
            for col in xrange(k):
                if B[row][col] != 0:
                    for i, val in nums.get(row, {}).items():
                        ret[i][col] += val * B[row][col] 
        return ret
        