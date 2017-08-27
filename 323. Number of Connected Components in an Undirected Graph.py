class Solution(object):
    
    # dfs: O(E) time, O(E) space
    def countComponents(self, n, edges):
        def dfs(node):
            if node in self.adj:
                neighbors = self.adj[node]
                del self.adj[node]
                for n in neighbors:
                    dfs(n)
        ret = 0
        self.adj = {i: [i] for i in xrange(n)}
        for a, b in edges:
            self.adj[a] += [b]
            self.adj[b] += [a]  # bug: undirected graph
            
        for a, b in edges:
            if a in self.adj:  # check visited
                ret += 1
                dfs(a)
        return ret + len(self.adj)
    
    
    # union find: O(V + E) time, O(V) space
    def countComponents(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        def find(node):
            if self.root[node] == node:
                return node
            self.root[node] = find(self.root[node])
            return self.root[node]
        
        self.root = {i:i for i in xrange(n)}
        ret = n
        for a, b in edges:
            root_a = find(a)
            root_b = find(b)
            if root_a != root_b:
                self.root[root_a] = root_b   # bug: root[a] = b
                ret -= 1
        return ret
        