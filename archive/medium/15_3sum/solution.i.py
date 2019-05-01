'''
Brief:
    iterate 2 number, and get the third num3 = 0 - num1 - num2, check if the num3 is in nums;

Complexity:
    O(N2), but I got a Time limited Exceed.
    the worst: the result list is the nums list, then the complexity maybe O(N3)
'''


class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        d = {}
        rlist = []
           
        for index, n in enumerate(nums):
            d[n] = index
            
        i = 0
        while (i < len(nums)): 
            j = i + 1
            while (j < len(nums)):
                sub = 0 - nums[i] - nums[j]
                if (sub) in d:                    
                    if d[sub]  > j:
                        tlist = sorted([nums[i], nums[j], sub])
                        if tlist in rlist:
                            pass
                        else:
                            rlist.append(tlist)
                j += 1
            i += 1
        
        return rlist
