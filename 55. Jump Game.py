class Solution(object):
    
    # !! Dynamic Programming: O(N2) time, O(N) space, TLE
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if nums == [0]: return True         # corner case
        can = [0] * (len(nums)-1) + [1]     # can reach himself
        for i in xrange(len(nums)-2, -1, -1):
            furthestJump = min(nums[i] + i, len(nums)-1)
            for j in xrange(i+1, furthestJump+1):
                if can[j] == 1: 
                    can[i] = 1
                    break
        return can[0] == 1

    # Greedy?: O(N) time, O(1) space
    def canJump(self, nums):
        if nums == [0]: return True         # corner case
        start, end, allZero = 0, 0, False
        while not allZero:
            allZero = True
            for i in xrange(start, end+1):
                if nums[i] != 0: 
                    start += 1
                    end = max(end, nums[i] + i)  # bug: update end index
                    allZero = False
                    
                if end >= len(nums)-1:
                    return True
        return False

    # !! Greedy: O(N) time, O(1) space
    def canJump(self, nums):
        if nums == [0]: return True         # corner case
        leftMostReachable = len(nums)-1
        for i in xrange(len(nums)-2, -1, -1):
            furthestJump = nums[i] + i
            if furthestJump >= leftMostReachable:
                leftMostReachable = i
        return leftMostReachable == 0
        
        