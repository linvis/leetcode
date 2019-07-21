
#  题目：判断二叉树是否是镜像对称

#  思路：想到的是，将右子树反转，然后判断两个子树是否相同

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        
        def restruct(node):
            if not node:
                return
            
            tmp = node.left
            node.left = node.right
            node.right = tmp
            
            restruct(node.left)
            restruct(node.right)
            
        def check(node1, node2):
            if node1 == None and node2 == None:
                return True
            
            if node1 and node2:
                if node1.val != node2.val:
                    return False
                
                if not check(node1.left, node2.left):
                    return False
                
                if not check(node1.right, node2.right):
                    return False
                
                return True
            
            return False
        
        restruct(root.right)
        
        return check(root.left, root.right)


#  正确的递归做法
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def check(node1, node2):
            if node1 == None and node2 == None:return True
            if node1 == None or node2 == None: return False
            if node1.val != node2.val:
                return False
            
            return check(node1.left, node2.right) and check(node1.right, node2.left)
        
        return check(root, root)


#  循环解法，使用双向队列
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        
        queue = [root.left, root.right]
        
        while len(queue) > 0:
            left = queue.pop(0)
            right = queue.pop(-1)
            
            if left == None and right == None:
                continue
            if left == None or right == None:
                return False
            
            if left.val != right.val:
                return False
            
            queue.insert(0, left.right)
            queue.insert(0, left.left)
            
            queue.append(right.left)
            queue.append(right.right)
        
        return True
