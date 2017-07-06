# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    
    # iterative: O(m+n) time &  space
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        ret = ListNode(-1)
        dummy = ret
        while l1 and l2:
            if l1.val <= l2.val:
                dummy.next = ListNode(l1.val)
                l1, dummy = l1.next, dummy.next
            else:
                dummy.next = ListNode(l2.val)
                l2, dummy = l2.next, dummy.next
        while l1:
            dummy.next = ListNode(l1.val)
            l1, dummy = l1.next, dummy.next
        while l2:
            dummy.next = ListNode(l2.val)
            l2, dummy = l2.next, dummy.next
        return ret.next
    
    # more elegant iterative: O(m+n) time & space
    def mergeTwoLists(self, l1, l2):
        ret = ListNode(-1)
        dummy = ret
        while l1 and l2:
            if l1.val <= l2.val:
                dummy.next, l1 = ListNode(l1.val), l1.next
            else:
                dummy.next, l2 = ListNode(l2.val), l2.next
            dummy = dummy.next
            
        dummy.next = l1 if l1 else l2
        return ret.next

    # recursive: O(m+n) time & space
    def mergeTwoLists(self, l1, l2):
        if not l1 or not l2:
            return l1 or l2
        if l1.val <= l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        else:
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2