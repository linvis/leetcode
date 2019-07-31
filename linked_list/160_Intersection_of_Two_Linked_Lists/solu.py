
#  题目：判断两个链表是否相交, 并返回相交点

#  思路：hash来做, time O(m + n), space O(m)

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        hash_table = {}
        
        while headA:
            hash_table[headA] = 1
            headA = headA.next

        while headB:
            if headB in hash_table:
                return headB
            
            headB = headB.next
        
        return None



#  要求 time O(m + n), space O(1)
#  思路：没做出来，

#  官方思路
#  双指针，A从headA开始，如果遍历到None，然后转而指向headB，继续遍历headB，同样B指针也是

#  如果A，B遍历到同一个点，则证明该点为相交点

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        p_A = headA
        p_B = headB
        
        while p_A and p_B:
            if p_A == p_B:
                return p_A
            
            p_A = p_A.next
            p_B = p_B.next
            
            if p_A == None and p_B == None:
                return None
            
            if p_A == None:
                p_A = headB
            
            if p_B == None:
                p_B = headA

        return None
