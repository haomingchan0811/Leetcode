class Solution(object):
    
    # hash table: O(N) time & space
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        def extract(f):
            name = ''
            for i, c in enumerate(f):
                if c == '(':
                    return (name, f[i+1:-1])
                name += c
                
        files = {}
        for path in paths:
            path = path.split()
            directory = path[0]
            for f in path[1:]:
                name, content = extract(f)
                files[content] = files.get(content, []) + [directory + '/' + name]
        # return [f for key, f in files.items()]  # bug: return common files only
        return [f for key, f in files.items() if len(f) > 1]