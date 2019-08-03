
#  题目：返回链表中第K个大的元素

#  思路：使用K个stack，去卡，time O(KN)

import numpy as np
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        if k < np.log2(len(nums)):
            stack = nums[:k]
            stack = sorted(stack, reverse=True)

            for i in range(k, len(nums)):
                if nums[i] <= stack[-1]:continue
                for j in range(len(stack)):
                    if nums[i] > stack[j]:
                        stack.insert(j, nums[i])
                        stack.pop(-1)
                        break
            return stack[-1]    
        else:
            nums = sorted(nums, reverse=True)
            return nums[k-1]





#  第二种，使用最大堆/最小堆，time O(N + KlogN) or O(N + (N - K)logN)

import heapq
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        res = 0
        use_max = False
        if k < len(nums) / 2:
            nums = [-num for num in nums]
            use_max = True
        else:
            k = len(nums) - k + 1
                
        heapq.heapify(nums)
        
        for _ in range(k):
            res = heapq.heappop(nums)
            
        if use_max:
            return -res
        else:
            return res
