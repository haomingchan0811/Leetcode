import gc
class Solution(object):
    
    # # brute force: O(mn*len) time, O(m) space, MLE???
    # def replaceWords(self, dict, sentence):
    #     """
    #     :type dict: List[str]
    #     :type sentence: str
    #     :rtype: str
    #     """
    #     ret = ""
    #     word, i = "", 0
    #     while i < len(sentence):
    #         while i < len(sentence) and sentence[i] != ' ':
    #             word += sentence[i]
    #             i += 1
    #         target = None
    #         for root in dict:
    #             if root in word and root == word[:len(root)]:
    #                 if target is None or len(target) > len(root):
    #                     target = root
    #         ret += (target if target else word) + (' ' if i < len(sentence) else '')
    #         word = ""
    #         i += 1
    #     gc.collect()
    #     return ret
    
    # pythonic brute force: O(mn*len) time, O(m) space
    def replaceWords(self, dict, sentence):
        rootset = set(dict)    # key to O(1) lool up
        def replace(word):
            for i in xrange(len(word)):
                if word[:i] in rootset:
                    return word[:i]
            return word
        return " ".join(map(lambda x: replace(x), sentence.split()))
        