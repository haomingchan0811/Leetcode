# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    
    # reverse and add: O(N) time, O(1) space
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        def reverse(node):
            if not node:
                return node
            prev = None
            while node.next:
                temp = node.next
                node.next = prev
                prev = node
                node = temp
            node.next = prev
            return node
        
        if not l1:
            return l2
        if not l2:
            return l1
        l1 = reverse(l1)
        l2 = reverse(l2)
        ret, carry = ListNode(0), 0
        dummy = ret
        while l1 or l2:
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0
            temp = x + y + carry
            ret.val = temp % 10
            carry = temp / 10
            ret.next = ListNode(0)
            ret = ret.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        ret.val = 1 if carry else 0
        node = reverse(dummy)
        return node if node.val else node.next
    
#     # (IGNORE) store in list and transform: O(N) time, O(N) space
#     def addTwoNumbers(self, l1, l2):
#         if not l1:
#             return l2
#         if not l2:
#             return l1
#         len1, len2 = 0, 0 
#         dummy1, dummy2 = l1, l2
#         while l1:
#             len1 += 1
#             l1 = l1.next
#         while l2:
#             len2 += 1
#             l2 = l2.next
#         if len1 > len2:
#             dummy1, dummy2 = dummy2, dummy1
#             len1, len2 = len2, len1
        
#         temp = []
#         for i in xrange(len2 - len1):
#             temp.append(dummy2.val)
#             dummy2 = dummy2.next
#         while dummy2:
#             temp.append(dummy1.val + dummy2.val)
#             dummy1, dummy2 = dummy1.next, dummy2.next
        
#         carry = 0
#         for i in xrange(len(temp) - 1, -1, -1):
#             currSum = temp[i] + carry 
#             temp[i] = currSum % 10
#             carry = currSum / 10
#         ret = ListNode(1)
#         dummy = ret
#         for num in temp:
#             ret.next = ListNode(num)
#             ret = ret.next
#         return dummy if carry else dummy.next
            
    # ! store in list and transform: O(N) time, O(N) space
    def addTwoNumbers(self, l1, l2):
        if not l1:
            return l2
        if not l2:
            return l1
        arr1, arr2 = [], []
        while l1:
            arr1.append(l1.val)
            l1 = l1.next
        while l2:
            arr2.append(l2.val)
            l2 = l2.next
            
        m, n, carry = len(arr1) - 1, len(arr2) - 1, 0
        head, p = None, None
        while m >= 0 or n >= 0 or carry:
            currSum = (arr1[m] if m >= 0 else 0) + (arr2[n] if n >= 0 else 0) + carry
            carry = currSum / 10
            p = ListNode(currSum % 10)
            p.next = head     # brilliant idea
            head = p
            m, n = m - 1, n - 1
        return head
            
        
                
        