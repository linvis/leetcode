
#  题目：查找一个二叉树中，任意两个节点的最近公共祖先(LCA, the lowest common ancestor)

#  思路：DFS遍历找出两个节点，比较 O(N)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dfs(self, root, p, q):
        
        nums = 2
        res = []
        pathes = [[root], ]
        
        while pathes:
            nodes = pathes.pop(0) 
            path = nodes
            node = nodes[-1]
            
            if not node:continue
            
            if node.val == p.val or node.val == q.val:
                res += [path]
                nums -= 1
                
                if nums == 0:
                    return res
            
            if node.right:
                pathes = [path + [node.right]] + pathes
            
            if node.left:
                pathes = [path + [node.left]] + pathes
                
    
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        path_a, path_b = self.dfs(root, p, q)
        
        last = None
        while path_a and path_b:
            if path_a[0] == path_b[0]:
                last = path_a[0]
                path_a.pop(0)
                path_b.pop(0)
            else:
                break
        
        return last
