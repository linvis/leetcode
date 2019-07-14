#!/usr/bin/env python
# -*- coding=utf8 -*-

#  很简单，用hast table(dict)做就好了
#  复杂度 O(M + N)
#  值得注意的是 set 是基于dict的实现

class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        jewels = set(J)
        
        return sum(s in jewels for s in S)
