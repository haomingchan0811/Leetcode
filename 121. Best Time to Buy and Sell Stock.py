class Solution(object):
    
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
        