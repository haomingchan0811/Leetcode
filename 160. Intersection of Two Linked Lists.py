# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    
    # # reverse and search: O(m + n) time, O(m + n) space, WA: can not modify the linkedlist structure
    # def getIntersectionNode(self, headA, headB):
    #     """
    #     :type head1, head1: ListNode
    #     :rtype: ListNode
    #     """
    #     def rev(node):
    #         if node is None:
    #             return None
    #         prev = None
    #         while node and node.next:
    #             temp = node.next
    #             node.next = prev
    #             prev = node
    #             node = temp
    #         node.next = prev
    #         return node
    #     tailA = rev(headA)
    #     tailB = rev(headB)
    #     ret = None
    #     while tailA and tailB:
    #         if tailA == tailB:
    #             ret = tailA
    #             tailA = tailA.next
    #             tailB = tailB.next
    #         else:
    #             return ret
    #     return ret
        
    # # brute force: O(mn) time, O(1) space, TLE
    # def getIntersectionNode(self, headA, headB):
    #     while headA:
    #         dummyB = headB
    #         while dummyB:
    #             if dummyB == headA:
    #                 return headA
    #             dummyB = dummyB.next
    #         headA = headA.next
    #     return None     

    # hash table: O(max(m,n)) time, O(max(m,n)) space
    def getIntersectionNode(self, headA, headB):
        nodes = {}
        while headA:
            nodes[headA] = 1
            headA = headA.next
        while headB:
            if headB in nodes:
                return headB
            headB = headB.next
        return None   
    
    # !! Two pointersl, trick: offset the length difference with only two iteration
    # O(max(m, n)) time, O(1) space
    def getIntersectionNode(self, headA, headB):
        if not headA or not headB:
            return None
        dummyA = headA
        dummyB = headB
        # if a & b have different len, then we will stop the loop after second iteration when A = B = NULL
        while dummyA != dummyB:
            # at the end of first iteration, reset to the head of another linkedlist to counteract the length difference
            dummyA = dummyA.next if dummyA else headB
            dummyB = dummyB.next if dummyB else headA
        return dummyA

    