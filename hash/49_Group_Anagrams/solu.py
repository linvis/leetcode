
#  这题就是把拥有相同字母的单词，分到一个组里，
#  比如 'ate', 'eat'为一组，直接先sorted，然后hash来做

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash_word = {}
        for word in strs:
            sort_word = sorted(word)
            key_word = ''.join(sort_word)
            if key_word in hash_word:
                hash_word[key_word].append(word)
            else:
                hash_word[key_word] = [word]
        
        return [hash_word[key] for key in hash_word.keys()]
