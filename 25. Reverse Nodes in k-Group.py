# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    
    # recursive: O(N) time, O(1) space
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        dummy, count, valid = head, 0, False
        while dummy:
            count += 1
            dummy = dummy.next
            if count == k:
                valid = True
                break
        if not valid:
            return head
        dummy = head
        prev = None
        while count:
            temp = dummy.next
            dummy.next = prev
            prev = dummy
            dummy = temp
            count -= 1
        head.next = self.reverseKGroup(dummy, k)
        return prev
    
    
    # ! more elegant, recursive: O(N) time, O(1) space
    def reverseKGroup(self, head, k):
        curr, count = head, 0
        while curr and count != k:
            count += 1
            curr = curr.next
        if count == k:   # valid, can reverse
            prev = self.reverseKGroup(curr, k)
            while count:
                temp = head.next
                head.next = prev
                prev = head
                head = temp
                count -= 1
            head = prev
        return head
        
            
            
        
        