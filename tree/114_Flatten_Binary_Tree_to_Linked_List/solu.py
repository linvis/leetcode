
#  题目：把一个二叉树，转化为单右子树的形式

#  思路：尝试用了两个栈，分别放左节点和有节点，优先取左节点，进行组合，然后取右节点

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root:
            return
        
        last = cur = root
        left_nodes = [root.left]
        right_nodes = [root.right]
        
        while len(left_nodes) > 0 or len(right_nodes) > 0:
            if len(left_nodes) > 0:
                cur = left_nodes.pop(0)
                if not cur:continue
                    
                if cur.left:
                    left_nodes.insert(0, cur.left)
                if cur.right:
                    right_nodes.insert(0, cur.right)
                
                last.left = None
                last.right = cur
                last = cur
                continue
                
            if len(right_nodes) > 0:
                cur = right_nodes.pop(0)
                if not cur:continue
                    
                if cur.left:
                    left_nodes.insert(0, cur.left)
                if cur.right:
                    right_nodes.insert(0, cur.right)
                
                last.left = None
                last.right = cur
                last = cur
                continue


#  一个栈，但是空间开销并没有降低
#  时间反而降低了，51%(44ms)，上面的是96%(36ms)，有点奇怪
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root:
            return
        
        stack = [root]
        last = TreeNode(0)
        
        while len(stack) > 0:
            curr = stack.pop(0)
            
            if curr and curr.right:
                stack.insert(0, curr.right)
            
            if curr and curr.left:
                stack.insert(0, curr.left)
                
            if curr:
                last.left = None
                last.right = curr
                last = curr
            
