# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    
    # hash table: O(N) time & space
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        index, i = {}, 1
        while head:
            index[i] = head
            head = head.next
            i += 1
        if i - n == 1:   # BUG: remove first element 
            return index[2] if 2 in index else None   # corner case: one-elem list 
        else:
            index[i - n - 1].next = index[i - n + 1] if i - n + 1 in index else None 
        return index[1]
     
    # brute force: O(N) time, O(1) space
    def removeNthFromEnd(self, head, n):
        length, dummy = 0, head
        while head:
            head = head.next
            length += 1
        if length - n == 0:
            return dummy.next 
        
        head, i = dummy, 1
        while dummy and i != length - n:
            dummy = dummy.next
            i += 1
        dummy.next = dummy.next.next
        return head

    # two pointers: O(N) time, O(1) space
    def removeNthFromEnd(self, head, n):
        slow, fast, dummy = head, head, head
        while n:
            fast = fast.next
            n -= 1
        if fast:
            fast = fast.next
        else:
            return dummy.next
        while fast:
            slow = slow.next
            fast = fast.next
        slow.next = slow.next.next
        return head