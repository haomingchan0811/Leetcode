class Solution(object):
    
    # brute force, backtracking & two pointer: O(N!*N) time, O(n!) space, TLE
    def canPermutePalindrome(self, s):
        def isPalindrome(s):
            i, j = 0, len(s) - 1
            while i < j:
                if s[i] != s[j]:
                    return False
                i, j = i + 1, j - 1
            return True
        
        def permutation(chars, i, curr):
            can = False
            if i == len(chars):
                return isPalindrome(''.join(curr))
            for j in xrange(i, len(chars)):
                chars[i], chars[j] = chars[j], chars[i]
                can |= permutation(chars, i + 1, curr + [chars[i]])
                chars[i], chars[j] = chars[j], chars[i]
            return can
    
        chars = [c for c in s]
        return permutation(chars, 0, [])
    
    # hash table: O(N) time O(1) space
    def canPermutePalindrome(self, s):
        cnt, single = {}, 0
        for c in s:
            cnt[c] = cnt.get(c, 0) + 1
        for count in cnt.values():
            if count & 1:
                if single != 0:
                    return False
                else:
                    single += 1
        return True
        
        