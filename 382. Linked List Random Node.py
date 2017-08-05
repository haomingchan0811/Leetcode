# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

from random import randint
class Solution(object):

    # find the list length and generate random num b/t [1, length]
    # two pass: O(N) time, O(1) space
    def __init__(self, head):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        :type head: ListNode
        """
        self.head = head
        self.length = 0
        dummy = head
        while dummy:
            self.length += 1
            dummy = dummy.next

    def getRandom(self):
        """
        Returns a random node's value.
        :rtype: int
        """
        step = randint(0, self.length - 1)
        dummy = self.head
        for i in xrange(step):
            dummy = dummy.next
        return dummy.val

# ---------------------------------------------------- #

    # traverse the list, for each num replace answer with it with prob 1/i (i is the index + 1)
    # one pass: O(N) time, O(1) space
    def __init__(self, head):
        self.head = head

    def getRandom(self):
        length, ret = 0, None
        dummy = self.head
        while dummy:
            length += 1
            if randint(1, length) == length:
                ret = dummy.val
            dummy = dummy.next
        return ret


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()