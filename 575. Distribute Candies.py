class Solution(object):
    
    # hash table: O(N) time, O(N) space
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        cnt, total = {}, len(candies)
        for candy in candies:
            cnt[candy] = cnt.get(candy, 0) + 1
        return min(len(cnt), total / 2)
            
                
            
        
        