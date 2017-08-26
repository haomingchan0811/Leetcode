class Solution(object):
    
    # stack: O(N) time, O(N) space
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stack = []
        path = path.split('/')
        for elem in path:
            if elem in ['', '.'] or (elem == '..' and len(stack) == 0):
                continue
            else:
                if elem == '..':
                    stack.pop()
                else:
                    stack.append(elem)
        return '/' + '/'.join(stack)
                
        
        