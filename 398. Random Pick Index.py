class Solution(object):

    # hash table: O(N) time, O(N) space, MLE
    def __init__(self, nums):
        """
        :type nums: List[int]
        :type numsSize: int
        """
        self.index = {}
        for i, num in enumerate(nums):
            self.index[num] = self.index.get(num, []) + [i]

    def pick(self, target):
        """
        :type target: int
        :rtype: int
        """
        length = len(self.index[target])
        return self.index[target][random.randint(0, length - 1)]

    # !! reservior sampling: O(N) time, O(N) space
    def __init__(self, nums):
        self.nums = nums

    def pick(self, target):
        index = -1
        count = 0
        for i, num in enumerate(self.nums):
            if num == target:
                count += 1
                if random.randint(1, count) == 1:
                    index = i
        return index
        

# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)