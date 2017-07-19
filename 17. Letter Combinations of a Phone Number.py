class Solution(object):
    
    # dfs, back tracking: O(3^N) time, O(N) space
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if len(digits) == 0:
            return []
        ret = []
        digit2char = ['', '*', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        
        def dfs(digits, i, curr, ret):
            if i == len(digits):
                ret.append(curr)
            else:
                chars = digit2char[int(digits[i])]
                for char in chars:
                    dfs(digits, i + 1, curr + char, ret)
                    
        dfs(digits, 0, '', ret)
        return ret

    # ! iterative: O(3^N) time, O(N) space
    def letterCombinations(self, digits):
        ret = [""]
        digit2char = ['', '*', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        for digit in digits:
            d, temp = int(digit), []
            for c in digit2char[d]:
                for substr in ret:
                    temp.append(substr + c)
            ret = temp
        return ret if len(digits) else []
            
        