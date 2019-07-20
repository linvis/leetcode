
#  这题是中序遍历二叉树(左根右), 用循环做
#  我想到的一种解法是，用list来管理遍历的节点，查找到左节点，放到list，然后从list里依次pop出来
#  beat 14%, 算法比较低效，因为要用一个seen检查遍历过的节点

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if root == None:
            return []
        
        nodes = [root]
        ret = []
        seen = []

        while len(nodes) > 0:
            node = nodes[0]

            if node.left and node.left not in seen:
                nodes = [node.left] + nodes
                continue

            ret += [node.val]
            seen += [node]
            nodes.pop(0)

            if node.right and node.right not in seen:
                nodes = [node.right] + nodes

        return ret  
