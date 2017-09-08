class Solution(object):
    
    
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        stack, ret = [], 0
        for p in prices:
            while stack and stack[-1] > p:
                stack.pop()
            if stack == []:
                stack.append(p)
            else:
                ret = max(ret, p - stack[-1])
        return ret
    
    # record the minimal val & the maximum profit sofar: O(N) time, O(1) space
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        minPrice, maxProfit = float('inf'), 0
        for i in xrange(len(prices)):
            minPrice = min(minPrice, prices[i])
            maxProfit = max(maxProfit, prices[i] - minPrice)
        return maxProfit
                
            
                
                
        