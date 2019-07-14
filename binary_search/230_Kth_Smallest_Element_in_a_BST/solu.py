#!/usr/bin/env python
# -*- coding=utf8 -*-

#  这里写的有问题，复杂度是O(Nlog(N))
#  因为我调了sorted，我只是简单的遍历了一下二叉树，然后排序

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        nodes  = [root]
        val = []
        
        while (len(nodes) > 0):
            node = nodes.pop(0)
            val += [node.val]
            
            if node.left != None:
                nodes += [node.left]
            if node.right != None:
                nodes += [node.right]
                
        val = sorted(val)
        
        return val[k - 1]



#  实际上，用简单的前序遍历，就得着排好序的数组了
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        def in_order(node):
            if node:
                return in_order(node.left) + [node.val] + in_order(node.right)
            else:
                return []

        return in_order(root)[k - 1]
