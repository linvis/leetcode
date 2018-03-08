# -*- coding: utf-8 -*-
# Pw @ 2018-03-08 20:37:39

# recurisive

class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        l = '('
        r = ')'
        re = []
        if n == 1:
            return ['()']
        else:
            re_pre = self.generateParenthesis(n - 1)
            for r_s in re_pre:
                re.append(l + r + r_s)
                i_l = 0
                i_r = 0
                for s in r_s:
                    if s == l:
                        i_l += 1
                    else:
                        i_r += 1
                        if i_l == i_r:
                            re.append(l + r_s[:i_l+i_r] + r + r_s[i_l+i_r:])
                        else:
                            pass
        return re
                            
