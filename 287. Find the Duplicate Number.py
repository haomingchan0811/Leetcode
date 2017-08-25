class Solution(object):
    
    # bit manipulation, XOR: O(N) time, O(1) space, WRONG
    # There is only one duplicate number in the array, but it could be repeated more than once.
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ret = len(nums)
        for i in xrange(len(nums)):
            ret ^= nums[i] ^ (i + 1)
        return ret 
    
    # sort: O(NlogN) time, O(1) space
    def findDuplicate(self, nums):
        nums.sort()
        for i in xrange(1, len(nums)):
            if nums[i] == nums[i - 1]:
                return nums[i]
        return None
    
    # negate trick: O(N) time, no space
    def findDuplicate(self, nums):
        for num in nums:
            index = abs(num)
            if nums[index] < 0:
                return index
            nums[index] *= -1
        return None
    
    # !! binary search: for mid, count num if num <= mid, if count > mid, shrink the search grid to [1, mid], else [mid+1, n]
    # O(NlogN) time, O(1) space
    def findDuplicate(self, nums):
        lo, hi = 1, len(nums) - 1  # init search grid: [1, n]
        while lo < hi:
            mid = lo + (hi - lo) / 2
            count = 0
            for num in nums:
                if num <= mid:
                    count += 1
            if count > mid:
                hi = mid
            else:
                lo = mid + 1
        return lo
    
    # !! slow & fast pointers: same as find entry point of linked list cycle - 142. Linked List Cycle II
    # O(N) time, O(1) space
    def findDuplicate(self, nums):
        slow = nums[0]
        fast = nums[nums[0]]
        while slow != fast:
            slow = nums[slow]
            fast = nums[nums[fast]]
        head = 0     # init new pointer start from begining, slow start from intersection pointer
        while head != slow:   # at last they will meet at entry point of cycle
            head = nums[head]
            slow = nums[slow]
        return head