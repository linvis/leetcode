"""
For any character in str, it must have two status: having repeat before or not.
So traverse every character
The time is O(n)
"""
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        hast_str = {}
        max_len = 0
        repeat = 0        
        for idx, c in enumerate(s):            
            if c in hast_str:
                repeat = max(repeat, hast_str[c] + 1)
            hast_str[c] = idx
            max_len = max(max_len, idx -repeat + 1)
        return max_len   
