# -*- coding: utf-8 -*-
# Pw @ 2018-03-05 23:21:31

# push left symbol into a stack, if get a right symbol,
# compare it and the value in the stack
# O(n)

class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        kmaps = {'(':')', '{':'}', '[':']'}
        q = []
        if s == "":
            return True
        else:
            for c in s:
                if c in kmaps.keys():
                    q.append(c)
                else:
                    if len(q) == 0:
                        return False
                    
                    if c == kmaps[q[-1]]:
                        q.pop()
                    else:
                        return False
                    
            if len(q) == 0:
                return True
            else:
                return False
