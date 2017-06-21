class Solution(object):
    
    # brute force: O(N) time, O(1) space
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ret = [float('-inf')] * 3
        for num in nums:
            if num not in ret:  # bug
                if num > ret[0]: ret = [num, ret[0], ret[1]]
                elif num > ret[1]: ret = [ret[0], num, ret[1]]
                elif num > ret[2]: ret = [ret[0], ret[1], num]
        return ret[0] if float('-inf') in ret else ret[2]
        
    # set & priority queue: O(N) time, O(1) space
    def thirdMax(self, nums):
        ret = [float('-inf')] * 3
        for num in nums:
            if num > ret[0] and num not in ret:
                heapq.heappushpop(ret, num)
                print ret
        # bug: else ret[2] -> heap内部非有序 
        return ret[0] if ret[0] != float('-inf') else max(ret)