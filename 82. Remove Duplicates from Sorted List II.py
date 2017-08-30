# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    
    # hash table: O(N) time, O(N) space
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        curr, count = head, {}
        while curr:
            count[curr.val] = count.get(curr.val, 0) + 1
            curr = curr.next
            
        dummy = ListNode(None)
        dummy.next = head
        ret = dummy
        while dummy and dummy.next:
            if count.get(dummy.next.val, 0) == 1:
                dummy = dummy.next 
            else:
                dummy.next = dummy.next.next
        return ret.next
    
    # !! brute force: O(N) time, O(1) space
    def deleteDuplicates(self, head):
        dummy = ListNode(None)
        dummy.next = head
        prev, curr = dummy, head
        while curr and curr.next:
            if curr.val == curr.next.val:
                curr = curr.next
            elif prev.next == curr:
                prev = curr
                curr = curr.next
            else:
                prev.next = curr.next
                curr = curr.next
        if prev.next != curr:
            prev.next = None
        return dummy.next
        
                
        