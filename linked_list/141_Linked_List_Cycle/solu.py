
题目：查找链表中是否有回路

思路：hash

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        hash_table = {}
        while head:
            if head in hash_table:
                return True
            else:
                hash_table[head] = 1
                
            head = head.next
        
        return False


使用O(1)的空间复杂度
快慢指针，关键在于，快指针比慢指针快2，这样如果有回路，总会追上慢指针

class Solution(object):
    def hasCycle(self, head):
        if head == None or head.next == None:
            return False
        
        slow = head
        fast = head.next
        
        while slow != fast:
            if fast.next == None or fast.next.next == None:
                return False
            
            slow = slow.next
            fast = fast.next.next
            
        return True
