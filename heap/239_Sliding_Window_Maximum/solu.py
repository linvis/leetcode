
#  O(Nlogk)

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res = []
        if not nums:return res
        
        for i in range(0, len(nums) - k + 1):
            win = nums[i:i + k] 
            res.append(max(win))
        
        return res
            

#  尝试使用O(N)
