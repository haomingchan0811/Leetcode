import random
class RandomizedSet(object):

    # hash table: O(1) time, O(N) space
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.ind2val = {}
        self.val2ind = {}
        self.indBuffer = []

    def insert(self, val):
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        if val not in self.val2ind:
            if self.indBuffer:
                ind = self.indBuffer.pop()
            else:
                ind = len(self.ind2val) 
            self.val2ind[val] = ind
            self.ind2val[ind] = val
            return True
        return False

    def remove(self, val):
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        :type val: int
        :rtype: bool
        """
        if val in self.val2ind:
            ind = self.val2ind[val]
            del self.val2ind[val]
            del self.ind2val[ind]
            self.indBuffer.append(ind)
            return True
        return False

    def getRandom(self):
        """
        Get a random element from the set.
        :rtype: int
        """
        total = len(self.val2ind) + len(self.indBuffer)
        while total:
            n = random.randint(0, total - 1)
            if n in self.ind2val:
                return self.ind2val[n]


    # !! hash table: O(1) time, O(N) space
    # when remove 'val', swap 'val' with the last elem and update the index
    def __init__(self):
        self.val2ind = {}
        self.nums = []

    def insert(self, val):
        if val not in self.val2ind:
            self.val2ind[val] = len(self.nums)
            self.nums.append(val)
            return True
        return False

    def remove(self, val):
        if val in self.val2ind:
            ind = self.val2ind[val]
            lastElem = self.nums[-1]
            self.val2ind[lastElem] = ind
            self.nums[ind] = lastElem
            self.val2ind.pop(val, 0)
            self.nums.pop()
            return True
        return False

    def getRandom(self):
        if self.nums:
            n = random.randint(0, len(self.nums) - 1)
            return self.nums[n]


    # better 
    def __init__(self):
        self.indices = {}
        self.nums = []
        self.capacity = 0

    def insert(self, val):
        if val in self.indices:
            return False
        if self.capacity == len(self.nums):
            self.nums.append(val)
        else:
            self.nums[self.capacity] = val
        self.indices[val] = self.capacity
        self.capacity += 1
        return True
        

    def remove(self, val):
        if val not in self.indices:
            return False
        currIdx = self.indices[val]
        last, lastIdx = self.nums[self.capacity - 1], self.capacity - 1
        self.nums[currIdx] = last
        self.indices[last] = currIdx
        del self.indices[val]
        self.capacity -= 1
        return True
        
    def getRandom(self):
        return self.nums[random.randint(0, self.capacity - 1)]

# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()