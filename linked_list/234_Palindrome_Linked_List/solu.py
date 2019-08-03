
#  题目：检查链表是否是回文的形式 [1, 0, 1], [1, 0, 0, 1]

#  思路：要求time O(N) space O(1)
      #  反转前半部分链表，和后半部分比较


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


#  我这里查询第一遍为了获取链表长度, 第二遍才反转链表
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head or not head.next:return True
        
        link_len = 0
        link_head = head
        while link_head:
            link_len += 1
            link_head = link_head.next
        
        half_len = int((link_len - 1) / 2)
        
        # reverse from half
        left_len = 0
        pre = None
        while head:
            if left_len == half_len:
                break
            left_len += 1
                
            cur = head.next
            head.next = pre
            pre = head
            head = cur
            
        if link_len % 2 == 0:
            # 0 1 1 0
            left = head
            right = head.next
            head.next = pre
        else:
            # 1 0 1
            right = head.next
            left = pre
        
        while left and right:
            if left.val != right.val:
                return False
            left = left.next
            right = right.next
        
        if left != right:
            return False
        else:
            return True


#  只遍历一遍链表的方式，快慢指针，快指针是慢指针的两倍

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head or not head.next:return True
        
        # reverse from half
        fast = head
        slow = head
        pre = None
        while fast and fast.next:
            
            fast = fast.next.next
                
            cur = slow.next
            slow.next = pre
            pre = slow
            slow = cur
       
        if fast:
            slow = slow.next
        
        while pre and slow:
            if pre.val != slow.val:
                return False
            pre = pre.next
            slow = slow.next
        
        return True
