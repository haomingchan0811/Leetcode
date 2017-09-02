class Solution(object):
    
    # dynamic programming: O(Nk2) time, O(nk) space
    def minCostII(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        if len(costs) == 0 or len(costs[0]) == 0:
            return 0
        n, k = len(costs), len(costs[0])
        # dp = [costs[0] for __ in xrange(n)]  # BUG: each dp[i] will remain the same update 
        # dp = [list(costs[0]) for __ in xrange(n)]  # right way to copy without dependency 

        dp = [[0 for _ in xrange(k)] for __ in xrange(n)]  # smallest cost of painting each color so far
        dp[0] = costs[0]  # base case
        for i in xrange(1, n):
            for j in xrange(k):
                dp[i][j] = min(dp[i - 1][:j] + dp[i - 1][j + 1:]) + costs[i][j]
        return min(dp[-1])


    # better dynamic programming: O(Nk) time, O(1) space
    def minCostII(self, costs):
        if len(costs) == 0 or len(costs[0]) == 0:
            return 0
        n, k = len(costs), len(costs[0])
        min1, min2 = (0, 0), (0, 1)   # keep the smallest two paints
        
        for i in xrange(n):
            min1_i, min2_i = (float('inf'), -1), (float('inf'), -1)  
            for j in xrange(k):
                curr = (min1[0] if min1[1] != j else min2[0]) + costs[i][j]
                
                if curr <= min1_i[0]:
                    min2_i, min1_i = min1_i, (curr, j)
                elif curr <= min2_i[0]:
                    min2_i = (curr, j)
                    
            min1, min2 = min1_i, min2_i 
        return min1[0]
                
            
        