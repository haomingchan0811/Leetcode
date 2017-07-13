# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    
    # reverse and compare: O(N) time & space
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head == None:    # corner case
            return True
        vals, prev = [], None
        while head.next:
            vals.append(head.val)
            temp = head.next
            head.next = prev
            prev = head
            head = temp   
        vals.append(head.val)
        head.next = prev
        
        i = 0
        while head:
            if head.val != vals[i]:
                return False
            i, head = i + 1, head.next
        return True

    # store values: O(N) time & space
    def isPalindrome(self, head):
        if head == None:    # corner case
            return True
        vals = []
        while head:
            vals.append(head.val)
            head = head.next
        i, j = 0, len(vals) - 1
        while i < j:
            if vals[i] != vals[j]:
                return False
            i, j = i + 1, j - 1
        return True

    # Two pointers, reverse half: O(N) time，O(1) space
    def isPalindrome(self, head):
        if not head or not head.next :    # corner case
            return True
        slow, fast, prev = head, head, None
        while fast and fast.next:
            temp, temp_fast = slow.next, fast.next
            slow.next = prev
            prev = slow
            slow = temp 
            # bug: fast.next.next (WRONG) -> at first, (head == fast), after slow changes head.next, fast.next = None
            fast = temp_fast.next   
            
        left, right = None, None
        if fast:  # odd length list
            left, right = prev, slow.next
        else:
            left, right = prev, slow
        
        while left and right:
            if left.val != right.val:
                return False
            left, right = left.next, right.next
        return True
            
        