class Solution(object):
    
    # Naive: O(N) time & space, 81.42%
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ret = list()
        for i in xrange(1, n + 1):
            if i % 15 == 0:
                ret.append("FizzBuzz")
            elif i % 5 == 0:
                ret.append("Buzz")
            elif i % 3 == 0:
                ret.append("Fizz")
            else:
                ret.append(str(i))
        return ret
    
    # List Comprehension: O(N) time & space, 58.17%
    def fizzBuzz(self, n):
        return [('Fizz' * (not i % 3) + 'Buzz' * (not i % 5)) or str(i) for i in xrange(1, n + 1)]

