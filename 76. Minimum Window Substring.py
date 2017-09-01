class Solution(object):
    
    # brute force: O(N3) time, O(N) space, TLE
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        if t == "" or len(t) > len(s):
            return ""
        count = collections.Counter(t)
        for length in xrange(1, len(s) + 1):
            for start in xrange(0, len(s) - length + 1):
                end = start + length 
                cnt = collections.Counter(s[start:end])
                isSub = True
                for key, val in count.items():
                    if (not key in cnt) or (val > cnt[key]):
                        isSub = False
                        break
                if isSub:
                    return s[start:end]
        return ""
    
    # two pointers and hash table: O(N) time, O(N) space
    def minWindow(self, s, t):
        if t == "" or len(t) > len(s):
            return ""
        count = collections.Counter(t)
        need = set(t)
        start, end, ret = 0, 0, None
        while end < len(s):
            if s[end] in count:
                count[s[end]] -= 1
                if count[s[end]] == 0:
                    need.remove(s[end])              
                    
            while start <= end and len(need) == 0:      # find a hit
                if ret is None or len(ret) > end - start + 1:
                    ret = s[start: end + 1]
                if s[start] in count:
                    count[s[start]] += 1
                    if count[s[start]] > 0:
                        need.add(s[start])
                start += 1
            end += 1
        return ret if ret else ""

    # more elegant, two pointers: O(N) time, O(N) space
    def minWindow(self, s, t):
        if t == "" or len(t) > len(s):
            return ""
        need, missing = collections.Counter(t), len(t)
        start, ret = 0, None
        
        for end, c in enumerate(s):
            missing -= int(need[c] > 0)
            need[c] -= 1
            
            while start <= end and missing == 0:        # find a hit
                if ret is None or len(ret) > end - start + 1:
                    ret = s[start: end + 1]
                need[s[start]] += 1
                missing += int(need[s[start]] > 0)
                start += 1
        return ret if ret else ""
                    
                
        