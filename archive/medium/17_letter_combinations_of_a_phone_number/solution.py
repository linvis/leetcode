# -*- coding: utf-8 -*-
# Pw @ 2018-03-05 21:18:38

# reference from https://leetcode.com/problems/letter-combinations-of-a-phone-number/discuss/8070/One-line-python-solution
# 我的初始算法：通过构建树的形式，将新字符插入原有树的结构
# 参考代码算法：遍历一个字符，输出所有结果，在已知结果上添加新字符，有点贪婪算法的意思

from functools import reduce 
class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if digits == '':
            return []
        else:
            kvmaps = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
            }
            return reduce(lambda acc, digit: [x + y for x in acc for y in kvmaps[digit]], digits, [''])
