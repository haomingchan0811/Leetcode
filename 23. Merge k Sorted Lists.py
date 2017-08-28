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
        head = ListNode(-1)
        dummy = head
        heap = []   # heap
        for node in lists:
            if node is not None:
                heapq.heappush(heap, (node.val, node))
                
        while heap:
            val, node = heapq.heappop(heap)
            dummy.next = node
            node = node.next
            dummy = dummy.next
            if node is not None:
                heapq.heappush(heap, (node.val, node))
        return head.next
        
        