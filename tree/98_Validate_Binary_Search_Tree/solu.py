
题目：检查一个二叉树是否是二叉搜索树

思路：递归
      中序遍历

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        stack = []
        last = float('-inf')
        curr = root
        
        while len(stack) > 0 or curr != None:
            
            while curr != None:
                stack.insert(0, curr)
                curr = curr.left
            
            curr = stack.pop(0)
                
            if last >= curr.val:
                return False
            
            last = curr.val
            curr = curr.right
            
        return True


class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        
        def check(root, lower = float('-inf'), upper = float('inf')):
            if root == None:
                return True
           
            if root.val <= lower or root.val >= upper:
                return False
            
            if not check(root.left, lower, root.val):
                return False
            if not check(root.right, root.val, upper):
                return False
            
            return True
            
        return check(root)

