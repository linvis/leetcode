"""
This solution can't pass the leetcode testing, because it spent too much time.
and I do some test(not all), it all works.

The algorithm is:
    a example str: "xxxxbxxxxbxxx"
    traverse the str, find two repeat character, remember its idx.
    the first 'b' index is 4, the second is 9, so divid it to two substring,
    one is s[start:4], the other is s[5:end], so the longest substring must be in the two substring.
    iterate them to fing the longest.
"""


class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        hash_str = {}
        start = 0
        end = len(s)
        p = 0
        q = 0
        for idx, c in enumerate(s):
            if c in hash_str:
                p = self.lengthOfLongestSubstring(s[start: idx])
                q = self.lengthOfLongestSubstring(s[hash_str[c] + 1 : end])
            hash_str[c] = idx

        if (p == 0 and q == 0):
            return len(s)
        else:
            return max(p, q)
