# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    
    # Iteratively: O(N) time, O(1) space
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next: return head
        prev = None
        while head and head.next:
            temp = head.next
            head.next = prev
            prev = head
            head = temp
        head.next = prev
        return head

    # Recursively: O(N) time, O(1) space
    def reverseList(self, head):
        if not head or not head.next:
            return head
        node = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return node