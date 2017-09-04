class Solution(object):
    
    # ! stack: O(N) time, O(N) space
    def exclusiveTime(self, n, logs):
        """
        :type n: int
        :type logs: List[str]
        :rtype: List[int]
        """
        if n == 0 or len(logs) < 2:
            return []
        stack = [int(logs[0].split(':')[0])]
        ret = [0 for i in range(n)]
        prevTime = 0
        
        # bug: can recursively call self, not necessarily the end
        for i in xrange(1, len(logs)):
            ids, op, currTime = logs[i].split(":")
            currTime = int(currTime) + (1 if op == 'end' else 0)
            ids = int(ids)               # bug!!!!: string '123' < '13'
            
            if stack:
                ret[stack[-1]] += currTime - prevTime
            if op == 'start': 
                stack.append(ids)
            else:
                stack.pop()
            prevTime = currTime
        return ret
                
                
                
        