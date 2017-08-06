class Solution(object):
    
    # backtracking, dfs: O() time
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        def dfs(nums, index, length):
            if index == length:
                self.ret += 1
                return 
            for i in xrange(index, 10):
                nums[i], nums[index] = nums[index], nums[i]
                dfs(nums, index + 1, length)
                nums[i], nums[index] = nums[index], nums[i]
        if n == 0:
            return 1
        self.ret = 10
        for length in xrange(2, min(10, n) + 1):  # when n > 10, no valid number 
            dfs(range(10), 0, length)
            self.ret -= reduce(operator.mul, [x for x in xrange(9, 10 - length, -1)])  # leading zero
        return self.ret
                
            
                
            
        