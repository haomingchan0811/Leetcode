class Solution(object):
    
    # # brute force: O(logN)time, O(n) space, TLE
    # def lastRemaining(self, n):
    #     """
    #     :type n: int
    #     :rtype: int
    #     """
    #     num, size, left = range(1, n+1), n, True
    #     while size > 1:
    #         nums = range(n) if left else range(n-1, -1, -1)
    #         skip, left = False, False if left else True
    #         for i in nums:
    #             if num[i] != -1:
    #                 if skip == False:
    #                     num[i], skip = -1, True
    #                 else: skip = False
    #         size -= (size+1) / 2
    #     return filter(lambda x: x != -1, num)[0]
    
    # # brute force: O(logN)time, O(n) space, TLE
    # def lastRemaining(self, n):
    #     num, left = range(1, n+1), True
    #     while len(num) > 1:
    #         if left:
    #             remain = filter(lambda (x, y): x % 2 == 1, enumerate(num))
    #         else:
    #             remain = filter(lambda (x, y): x % 2 == (1 if len(num) & 1 else 0), enumerate(num))
    #         left = False if left else True
    #         num = map(lambda (x, y): y, remain)
    #     return num[0] 
    
    # !!!! Record head, stepSize and seqSize: O(logN)time, O(1) space
    # https://discuss.leetcode.com/topic/59293/java-easiest-solution-o-logn-with-explanation
    def lastRemaining(self, n):
        left, head, seqSize, stepSize = True, 1, n, 1
        while seqSize > 1:
            # update head when starting from left OR from right and seqSize is odd
            if left or (seqSize & 1):  
                head += stepSize
            seqSize /= 2
            stepSize *= 2
            left = not left
        return head

        
        