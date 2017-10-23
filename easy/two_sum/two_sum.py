class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hash_num = {}
        for idx, num in enumerate(nums): 
            if (target - num) in hash_num:
			"""
			a wrong usage:
			if hash_num.get(key):
			hash_num.get will return the value of key.
			so if the value is 0, it will not come into the if, make it error
			"""
                return [hash_num[target - num], idx]
            hash_num[num] = idx
        return None
