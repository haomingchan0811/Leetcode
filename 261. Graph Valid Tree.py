class Solution(object):
    
    # dfs, find circle: O(N) time, O(N) space
    def validTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: bool
        """
        def hasCircle(v, source):
            if self.visited[v]:
                return True
            self.visited[v] = True
            for neighbor in self.e[v]:
                if neighbor not in [v, source] and hasCircle(neighbor, v):
                    return True
            return False
        
        if n == 0:
            return False
        self.visited = [False for _ in range(n)]
        self.e = {i:[i] for i in range(n)}
        for edge in edges:
            s, t = edge[0], edge[1]
            self.e[s].append(t)
            self.e[t].append(s)
        # tree: all connected, no loop        
        return (not hasCircle(0, None)) and self.visited.count(False) == 0

    # union find: O(N) time, O(N) space
    def validTree(self, n, edges):
        def find(root):
            if self.root[root] == root:
                return root
            self.root[root] = find(self.root[root])
            return self.root[root]
        
        if n == 0:
            return False
        self.root = [i for i in range(n)]
        for edge in edges:
            root_s = find(edge[0])
            root_t = find(edge[1])
            if root_s == root_t:
                return False
            self.root[root_s] = root_t
        
        for i, root in enumerate(self.root):
            self.root[i] = find(root)
        return self.root.count(self.root[0]) == len(self.root)