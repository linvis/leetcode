
题目：层序遍历二叉树

思路：依次遍历一层内的所有节点，

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        
        path = [root]
        ans = []
        
        while len(path) > 0:
            nodes = [n for n in path]
            path.clear()
            
            ans += [[n.val for n in nodes]]
            
            for n in nodes:
                if n.left:
                    path.append(n.left)
                if n.right:
                    path.append(n.right)
           
        return ans
