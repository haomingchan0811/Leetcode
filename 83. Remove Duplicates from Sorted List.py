# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    
    # brute force: O(N) time, O(1) space
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = head
        prev = None
        while head:
            if prev is None or prev.val != head.val:
                if prev is not None:
                    prev.next = head 
                prev = head
            head = head.next  
        if prev is not None:
            prev.next = None   # bug: final assignment missing
        return dummy
    
    # !! more elegant, brute force: O(N) time, O(1) space
    def deleteDuplicates(self, head):
        curr = head
        while curr and curr.next:
            if curr.next.val == curr.val:
                curr.next = curr.next.next
            else:
                curr = curr.next
        return head
        