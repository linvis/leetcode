#  排列组合问题，给定n个数，输出所有组合
#  总的组合数是 n!
#  实际上，A(n) = A(n - 1) + n
#  对于第n个数，相当于前 n - 1个数组成的排列组合，然后n插入其中
#  比如 [1, 2]，对于3来说，它可以插入三个位置，组成 [3, 1, 2], [1, 3, 2], [1, 2, 3]

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
    
        if len(nums) <= 1:
            return [nums]

        last = self.permute(nums[0:-1])
        cur = []
        
        for node in last:
            for i in range(len(node) + 1):
                cur.append(node[0:i] + [nums[-1]] + node[i:])

        return cur

