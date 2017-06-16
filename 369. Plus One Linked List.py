# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    
    # Brute force, double reverse: O(N) time, O(1) space, 
    def plusOne(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        def reverseList(node):
            if not node or not node.next: return node
            prev = None
            while node and node.next:
                temp = node.next
                node.next = prev
                prev = node
                node = temp
            node.next = prev
            return node
            
        head = dummy = reverseList(head)
        carry, head.val = (head.val + 1) / 10, (head.val + 1) % 10
        while carry:
            if head.next:  
                head = head.next 
                carry, head.val = (head.val + carry) / 10, (head.val + carry) % 10
                print "-", carry, head.val
            else:   # bug: when head.next = None
                head.next, carry = ListNode(1), 0
        return reverseList(dummy)
    
    # !!! Two pointer: find the rightmost element to increase
    # O(N) time, O(1) space
    def plusOne(self, head):
        rightmost = ret = ListNode(0)
        ret.next = head
        while head:
            if head.val != 9: rightmost = head
            head = head.next
            
        rightmost.val += 1
        rightmost = rightmost.next
        while rightmost:
            rightmost.val = 0
            rightmost = rightmost.next
        return ret if ret.val else ret.next

            
        