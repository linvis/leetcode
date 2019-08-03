
#  题目：反转链表

#  思路：1->2->3->4->5->NULL

#  tail None
#  head 1

#  loop
    #  tmp  = head.next 
    #  head.next = tail
    #  tail = head
    #  head = tmp

time O(N), space O(1)


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        tail = None
        
        if not head:
            return head
        
        while head.next:
            tmp = head.next
            head.next = tail
            tail = head
            head = tmp
            
        head.next = tail     
        
        return head
        
