
题目：对链表排序，要求O(NlogN), 常数空间复杂度

思路：merge sort, 但是又个问题，递归的merge sort space是logN

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        fast = head
        slow = head
        
        if not head:return None
        
        if not fast.next:
            return fast
        
        if not fast.next.next:
            if fast.val > fast.next.val:
                head = fast.next
                fast.next.next = fast
                fast.next = None
                return head
            
        
        last = None
        while fast and fast.next:
            last = slow
            fast = fast.next.next
            slow = slow.next
            
        last.next = None
            
        left = self.sortList(head)
        right = self.sortList(slow)
        #  here where logN
        head = ListNode(0)
        res = head
        
        while left and right:
            if left.val < right.val:
                head.next = left
                left = left.next
                head = head.next
            else:
                head.next = right
                right = right.next
                head = head.next
        
        if left: head.next = left
        if right: head.next = right
            
        return res.next



#  改进版，如果说变量也算，那就没办法了
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        fast = head
        slow = head
        
        if not head:return None
        
        if not fast.next:
            return fast
        
        if not fast.next.next:
            if fast.val > fast.next.val:
                head = fast.next
                fast.next.next = fast
                fast.next = None
                return head
            
        
        last = None
        while fast and fast.next:
            last = slow
            fast = fast.next.next
            slow = slow.next
            
        last.next = None
            
        left = self.sortList(head)
        right = self.sortList(slow)
        
        if left.val < right.val:
            head = left
            left = left.next
        else:
            head = right
            right = right.next
        last = head
        
        while left and right:
            if left.val < right.val:
                head.next = left
                left = left.next
                head = head.next
            else:
                head.next = right
                right = right.next
                head = head.next
        
        if left: head.next = left
        if right: head.next = right
            
        return last
        

#  一种绝对的O(1)
#  把递归改成循环，bottom-to-up
#  先2，2，2大小的遍历merge
#  然后4，4，4大小的遍历merge
#  ...
#  每次step <<= 1
