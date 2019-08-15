

#  思路：贪婪插入
#  先sorted第一遍，然后用插入, 所以 time 会逼近 NlogN * k^2

class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        res = []
        for q in sorted(people, key=lambda x: x[1]):
            if not res:
                res.append(q)
            else:
                count = q[1]
                idx = len(res)
                for i in range(len(res)):
                    if q[0] <= res[i][0]:
                        count -= 1 
                    if count < 0:
                        #res.insert(i, q)
                        idx = i
                        break
                res.insert(idx, q)
        return res



#  更进一步，先同时排序
#  然后可以发现，按照 insert(p[1], p)可以直接插入

#  这种双排序, NlogN * klogk
#  第二次排序用快排

class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key = lambda x: (-x[0], x[1]))
        output = []
        for p in people:
            output.insert(p[1], p)
        return output
