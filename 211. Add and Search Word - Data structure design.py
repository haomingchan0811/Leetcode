class TrieNode(object):
    
    def __init__(self, char):
        self.char = char
        self.end = False
        self.children = {}

class WordDictionary(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode(None)
        

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: void
        """
        root = self.root
        for c in word:
            if c not in root.children:
                root.children[c] = TrieNode(c)
            root = root.children[c]
        root.end = True       

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        def helper(word, i, root):
            if i == len(word):
                return root.end
            if word[i] != '.':
                if word[i] not in root.children:
                    return False
                return helper(word, i + 1, root.children[word[i]])
            else:
                if root.children == {}:
                    return False
                for c in root.children:
                    if helper(word, i + 1, root.children[c]):
                        return True
                return False

        return helper(word, 0, self.root)
        

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)