# !!! Double linkedlist and hash map: O(1) time & space
class DLinkedNode(object):
    
    def __init__(self, key, val):
        self.prev = None
        self.next = None
        self.key = key
        self.val = val

class LRUCache(object):
        
    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.cap = capacity
        self.cache = {}
        
        # init double linked list with two dummy node head & tail
        self.head = DLinkedNode(-1, -1)        
        self.tail = DLinkedNode(-1, -1)
        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key in self.cache:
            node = self.cache[key]
            self.remove(node)
            self.add_to_head(node)
            return node.val
        return -1

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if key in self.cache:
            self.remove(self.cache[key])
        node = DLinkedNode(key, value)
        self.add_to_head(node)
        self.cache[key] = node
        
        if len(self.cache) > self.cap:
            LRU_Node = self.tail.prev
            self.remove(LRU_Node)
            del self.cache[LRU_Node.key]
    
    def remove(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev

    def add_to_head(self, node):
        node.prev = self.head
        node.next = self.head.next
        self.head.next = node
        node.next.prev = node


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)