from collections import Counter
class Solution(object):
    
    # hashtable & sort: O(NlogN) time, O(N) space
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        cnt = Counter(s)
        sorted_cnt = sorted(cnt.items(), key=lambda (x,y): y, reverse=True)
        return ''.join(map(lambda (x,y): x * y, sorted_cnt))
    
    # hashtable & heap: O(NlogN) time, O(N) space
    def frequencySort(self, s):
        cnt, h, ret = Counter(s), [], ''
        for (key, val) in cnt.items(): heapq.heappush(h, (val, key))
        # return ''.join(map(lambda (val, key): key * val, h))[::-1]  # WRONG: heap has no order inside
        while h: 
            val, key = heapq.heappop(h)
            ret += key * val
        return ret[::-1]
    
    # bucket sort: O(N) time, O(N) space
    def frequencySort(self, s):
        cnt, buckets, ret = Counter(s), [''] * (len(s)+1), ''
        for (key, val) in cnt.items(): 
            buckets[val] += key * val
        for i in xrange(len(s), 0, -1): 
            ret += buckets[i]
        return ret
        