
#  题目：从一个二叉树中，找到一条路径和=target，路径的起点/终点不需要从root到leaf

#  思路：DFS遍历 O(N)，我觉得是O(NlogN), 每次循环检查了logN次(logN是树的高度)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        if not root: return 0
        pathes = [[root]]
        res = 0
        
        while pathes:
            path = pathes.pop(0)
            
            target = sum
            for n in list(reversed(path)):
                target -= n.val
                if target == 0:
                    res += 1
            
            node = path[-1]
            
            if node.right:
                pathes = [path + [node.right]] + pathes
            if node.left:
                pathes = [path + [node.left]] + pathes
                
        return res
            
        
