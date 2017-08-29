# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    
    # hash table: O(E) time, O(V*E) space
    def cloneGraph(self, node):
        if node is None:
            return None    # corner case
        nodes = {}
        dummy1 = dummy2 = node
        queue = [dummy1]
        for n in queue:
            if n not in nodes:
                nodes[n] = UndirectedGraphNode(n.label)
                for neighbor in n.neighbors:
                    if neighbor not in nodes:
                        queue.append(neighbor)
                        
        queue, visited = [dummy2], set()
        for n in queue:
            if n not in visited:
                visited.add(n)
                for neighbor in n.neighbors:
                    nodes[n].neighbors.append(nodes[neighbor])
                    if neighbor not in visited:
                        queue.append(neighbor)
        return nodes[node]
                
            
        