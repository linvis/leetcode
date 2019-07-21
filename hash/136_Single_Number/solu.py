
#  题目：返回数组中只出现一次的元素

#  思路：hash

#  常规
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        hash_tab = {}
        
        for n in nums:
            if n not in hash_tab:
                hash_tab[n] = 1
            else:
                hash_tab[n] += 1
        
        for key, val in hash_tab.items():
            if val == 1:
                return key



#  反过来，反向删除hash中的元素，最后就剩下一个
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        hash_table = {}
        for i in nums:
            try:
                hash_table.pop(i)
            except:
                hash_table[i] = 1
        return hash_table.popitem()[0]
