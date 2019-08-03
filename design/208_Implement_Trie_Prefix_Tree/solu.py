
题目：构建一个Trie(搜索树)

思路：直接hash，另一种，是每个单词构建搜索树

class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.tokens = {}
        self.pre = {}
        

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        if word not in self.tokens:
            self.tokens[word] = 1
            for i in range(1, len(word) + 1):
                self.pre[word[:i]] = 1
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        if word in self.tokens:
            return True
        else:
            return False
        

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        if prefix in self.pre:
            return True
        else:
            return False
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
