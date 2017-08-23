class Solution(object):
    
    # dynamic programming: O(N) time, O(1) space
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        if len(flowerbed) == 1:
            return not (flowerbed[0] and n)
        plant = 0 if flowerbed[0] or flowerbed[1] else 1
        notPlant = 0
        for i in xrange(1, len(flowerbed)):
            if flowerbed[i] == 0:
                # bug: have to consider precedding elem flowerbed[i+1]
                notPlant_curr = max(notPlant, plant) 
                if flowerbed[i-1] or (flowerbed[i+1] if i+1 < len(flowerbed) else 0):
                    plant = max(notPlant, plant)
                else:
                    plant = notPlant + 1
                notPlant = notPlant_curr
                if max(plant, notPlant) >= n:
                    return True
        return max(plant, notPlant) >= n
    
    # find consecutive 0s: O(N) time, O(1) space
    def canPlaceFlowers(self, flowerbed, n):
        if len(flowerbed) == 1:
            return not (flowerbed[0] and n)
        ret, zeros = 0, 0
        for i in xrange(len(flowerbed)):
            if (flowerbed[i - 1] if i-1 >= 0 else 0) or (flowerbed[i + 1] if i+1 < len(flowerbed) else 0):
                ret += (zeros + 1) / 2
                zeros = 0
            elif flowerbed[i] == 0:  # bug: check 0
                zeros += 1
        ret += (zeros + 1) / 2
        return ret >= n
    
    # ! optimized: O(N) time, O(1) space
    def canPlaceFlowers(self, flowerbed, n):
        count = 0
        for i in xrange(len(flowerbed)):
            if flowerbed[i] == 0 and (i == 0 or flowerbed[i - 1] == 0) and (i == len(flowerbed) - 1 or flowerbed[i + 1] == 0):
                flowerbed[i] = 1
                count += 1
            if count >= n:
                return True
        return False
                    
        