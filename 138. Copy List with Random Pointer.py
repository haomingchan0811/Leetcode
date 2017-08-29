# Definition for singly-linked list with a random pointer.
# class RandomListNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class Solution(object):
    
    # hash table: O(N) time, O(N) space
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        if head is None:   # bug: boundry check
            return head
        new_nodes = {}
        dummy1 = dummy2 = head
        while dummy1:
            new_nodes[dummy1] = RandomListNode(dummy1.label)
            dummy1 = dummy1.next
        while dummy2:
            if dummy2.next:   # bug: check None
                new_nodes[dummy2].next = new_nodes[dummy2.next]   
            if dummy2.random:
                new_nodes[dummy2].random = new_nodes[dummy2.random]
            dummy2 = dummy2.next
        return new_nodes[head]