# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    
    # Brute force: O(max(m,n) time & space, 48.69%
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if (not l1) and (not l2): return None
        if not l1: return l2
        if not l2: return l1
        a, b = l1.val, l2.val
        root = ret = ListNode((a + b) % 10)
        l1, l2, carry = l1.next, l2.next, (a + b) / 10
        while l1 or l2 or carry:
            a, b = l1.val if l1 else 0, l2.val if l2 else 0
            ret.next = ListNode((a + b + carry) % 10)
            ret, carry = ret.next, (a + b + carry) / 10
            l1, l2 = l1.next if l1 else None, l2.next if l2 else None
        return root