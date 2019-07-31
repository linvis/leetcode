
#  题目：[2,7,9,3,1] 从list里，选择一个元素sum最大，但是不能挑选相邻的元素, 比如不能选择2, 7, 可以选择2, 9

#  思路：DP，S(n) = max(S(n - 1), S(n - 2) + n)

class Solution:
    def rob(self, nums: List[int]) -> int:
        last = [0, 0]
        
        for n in nums:
            if last[0] + n > last[1]:
                tmp = last[1]
                last[1] = last[0] + n
                last[0] = tmp
            else:
                last[0] = last[1]
        
        return max(last)
