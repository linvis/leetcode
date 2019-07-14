#!/usr/bin/env python
# -*- coding=utf8 -*-


#  想到了用队列/栈存数据，但是算法写的不对
#  从头开始遍历，导致复杂度不稳定，在 O(N) ~ O(N^2)
#  之间
#  如果出现, [37, 47, 37, 37, 47, 47, 47 ...]
#  这种格式，复杂度会趋向O(N^2)

class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        queue = []
        ret = [0] * len(T)
        
        for i in range(len(T)):
            
            if len(queue) > 0:
                for node in queue:
                    if T[i] > node[0]:
                        ret[node[1]] = i - node[1] 
                        node[1] = -1
                queue = [q for q in queue if q[1] != -1]
           
            if i == (len(T) - 1):
                ret[i] = 0
                break
            
            if T[i] < T[i + 1]:
                ret[i] = 1
            else:
                queue.append([T[i], i])
        
        return ret



#  正确使用stack的解法
#  从后往前遍历，依次压栈
#  比如，对于75， 此时已经压栈了, [73, 76, 72, 69, 71]
#  T = [73, 74, 75, 71, 69, 72, 76, 73]
#  然后，比较75和栈顶，依次pop，
#  直到找到符合的
#  复杂度是 O(N)
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        ret = [0] * len(T)
        stack = []
        
        for i in range(len(T) - 1, -1, -1):
            while stack and T[i] >= T[stack[-1]]:
                stack.pop(-1)
                
            if stack:
                ret[i] = stack[-1] - i
            
            stack.append(i)
       
        return ret
