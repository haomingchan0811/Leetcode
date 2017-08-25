# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    
    # Two pointers: O(N) time, O(1) space
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head == None: return False
        fast, slow = head, head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if fast == slow: return True
        return False
    
    # hash set: O(N) time & space
    def hasCycle(self, head):
        nodes = set()
        while head != None:
            if head in nodes: 
                return True
            nodes.add(head)
            head = head.next 
        return False

        