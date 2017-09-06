# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    
    # k pointers: O(sum(len(N)) * k) time, O(1) space, TLE
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        end, head = False, ListNode(-1)
        dummy = head
        while not end:
            index, minVal = -1, float('inf')
            for i, node in enumerate(lists):
                if node is not None and node.val < minVal:
                    minVal, index = node.val, i
            if index == -1:
                end = True
            else:
                dummy.next = ListNode(minVal)
                dummy = dummy.next
                lists[index] = lists[index].next
        return head.next
    
    # heap, more elegant: O(sum(len(N)) * logk) time, O(k) space
    def mergeKLists(self, lists):
        if len(lists) == 0:
            return None
        dummy = head = ListNode(None)
        h = []
        for i in xrange(len(lists)):
            if lists[i] is not None:  # bug: check null here
                heapq.heappush(h, (lists[i].val, lists[i]))
        while h:
            _, node = heapq.heappop(h)
            dummy.next = node
            dummy = dummy.next
            if node.next:
                heapq.heappush(h, (node.next.val, node.next))
        return head.next
        
        