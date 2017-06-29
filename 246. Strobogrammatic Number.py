class Solution(object):
    
    # hash table: O(N) time, O(1) space
    def isStrobogrammatic(self, num):
        """
        :type num: str
        :rtype: bool
        """
        pairs = {'6': '9', '9': '6', '1': '1', '0': '0', '8': '8'}
        for i in xrange((len(num)+1) / 2):
            if (num[i] not in pairs) or (pairs[num[i]] != num[len(num)-i-1]):
                return False
        return True
    
    # two pointer: O(N) time, O(1) space
    def isStrobogrammatic(self, num):
        """
        :type num: str
        :rtype: bool
        """
        pairs = ['69', '96', '11', '00', '88']
        for i in xrange((len(num)+1) / 2):
            if num[i] + num[len(num)-i-1] not in pairs:
                return False
        return True
            
        
        
        