# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    
    # # hash set: O(N) time, O(N) space
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        nodes = set()
        while head:
            if head in nodes:
                return head
            nodes.add(head)
            head = head.next
        return None
    
    # !! slow & fast pointers: O(N) time, O(1) space
    # two parts: 
    #    1. when fast == slow, they meet in some point X in the loop
    #    2. init a new pointer starting at head, the other start at X, they'll meet at entry point of loop 
    #    * Proof: https://leetcode.com/problems/linked-list-cycle-ii/discuss/
    def detectCycle(self, head):
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
            if slow == fast:      # has loop
                dummy = head
                while dummy != slow:
                    dummy = dummy.next
                    slow = slow.next
                return dummy
        return None
        