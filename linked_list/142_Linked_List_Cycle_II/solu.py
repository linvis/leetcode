
#  题目：判断链表中是否有回路，并返回回路的第一个节点

#  思路：限制O(1)空间复杂度的前提下，快慢指针，当使用快慢指针找到回路后，
      #  此时快慢指针有可能停在回路中的任意一个节点上，因此，从头开始，
      #  依次检查该节点是否在回路内, 该方法时间复杂度很高

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return None
        
        slow = head
        fast = head.next
        
        while slow != fast:
            if not slow.next or not fast.next or not fast.next.next:
                return None
            
            slow = slow.next
            fast = fast.next.next
        
        slow = slow.next
        
        while True:
            if slow == fast:
                head = head.next
                
            if head == slow:
                return head
            else:
                slow = slow.next


#  时间复杂度很低，空间复杂度很高
class Solution(object):
    def detectCycle(self, head):
        hash_table = {}
        
        while head:
            if head in hash_table:
                return head
            else:
                hash_table[head] = 1
            
            if not head.next:
                return None
            
            head = head.next
        return None
