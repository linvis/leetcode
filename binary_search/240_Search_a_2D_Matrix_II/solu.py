
#  题目：从一个 m * n矩阵中查找某个元素是否存在，矩阵的row和column都是按从小大大排序

#  [
  #  [1,   4,  7, 11, 15],
  #  [2,   5,  8, 12, 19],
  #  [3,   6,  9, 16, 22],
  #  [10, 13, 14, 17, 24],
  #  [18, 21, 23, 26, 30]
#  ]

#  思路：下意识的用二分查找，每次查找A[i][i], 如果比它大，那么就在A[i][i]之外
#  考虑到m 不等于 n，实际的复杂度 是 O(mlogn)(m < n) or O(nlogm)(m > n)

class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix or not matrix[0]: return False

        m = len(matrix)
        n = len(matrix[0])

        def binary_search(nums, target):
            center = int(len(nums) / 2)
            if target == nums[center]: return True

            if len(nums) <= 1: return False 

            if target < nums[center]:
                return binary_search(nums[0:center], target)
            if target > nums[center]:
                return binary_search(nums[center:], target)

        if m == 1:
            return binary_search(matrix[0], target)

        if n == 1:
            nums = [matrix[i][0] for i in range (m)]
            return binary_search(nums, target)


        idx = 0
        for i in range(min(m, n)):
            if target == matrix[i][i]:
                return True

            if target < matrix[i][i]:
                idx = i
                break

        if idx == 0:idx = min(m, n)


        matrix_r = [matrix[i][idx:] for i in range(m)]
        matrix_b = matrix[idx:]

        return self.searchMatrix(matrix_r, target) or self.searchMatrix(matrix_b, target)


#  但是这么做，是比较蠢的
#  实际上可以用 O(m + n)，查找比较每一行的最大元素，如果比最大元素小，那么一定在该行

class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        
        j = -1
        for row in matrix:
            if len(row) <= 0:continue
            while j + len(row) and row[j] > target:
                j -= 1
            
            if row[j] == target:
                return True
            
        return False
            

