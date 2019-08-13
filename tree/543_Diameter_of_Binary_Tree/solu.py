
题目：查找一棵树中，最长的路径

思路：DFS搜索就好了
A(root) = max(D(left) + D(right) + 1, A(left), A(right))

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if not root:return 0
        
        def depth(root):
            if not root: return 0, 0
            
            h1, s1 = search(root.left)
            h2, s2 = search(root.right)
            
            return max(h1 + 1, h2 + 1), max(s1, s2, h1 + h2 + 1)
       
        h, s = depth(root)
        
        return s - 1

