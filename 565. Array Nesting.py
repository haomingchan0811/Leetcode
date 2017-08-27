class Solution(object):
    
    # brute force: O(N2) time, O(N) space, TLE
    def arrayNesting(self, nums):
        ret = 0
        for i in xrange(len(nums)):
            n, count = nums[nums[i]], 1
            while n != nums[i]:
                n = nums[n]
                count += 1
            ret = max(ret, count)
        return ret
    
    # better brute force: O(N) time, O(N) space
    def arrayNesting(self, nums):
        ret, visited = 0, set()
        for i in xrange(len(nums)):
            if not nums[i] in visited:
                visited.add(nums[i])
                n, count = nums[nums[i]], 1
                while n != nums[i]:
                    n = nums[n]
                    visited.add(n)
                    count += 1
                ret = max(ret, count)
        return ret
    
    # !! better brute force without space: O(N) time, no space
    def arrayNesting(self, nums):
        ret = 0
        for i in xrange(len(nums)):
            if nums[i] != float('inf'):
                temp = nums[i]
                nums[i] = float('inf')
                n, count = nums[temp], 1

                while n != float('inf'):
                    temp = n
                    n = nums[n]
                    nums[temp] = float('inf')
                    count += 1
                ret = max(ret, count)
        return ret
        