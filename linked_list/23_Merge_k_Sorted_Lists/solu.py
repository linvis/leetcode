
#  假设k个list，每个list长度为N
#  几种思路，
#  第一种，遍历所有list上的数据，然后排序，时间复杂度O(NlogN)
#  第二种，每次遍历k个list的head，合并，O(Nk)，平均每个head要比较k次
#  第三种, divide and conquer，O(Nlogk)

#  很奇怪，我用的第三种，也是复杂度最低的，但是跑出来时间复杂度打败26%

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if len(lists) > 2:
            med = int(len(lists) / 2)
            
            ret = [self.mergeKLists(lists[:med])] + [self.mergeKLists(lists[med:])]
            
            return self.mergeKLists(ret)
        else:
            return self.mergeLists(lists)
        
    
    def mergeLists(self, lists):
        if len(lists) <= 1:
            return lists[0] if len(lists) == 1 else []
        else:
            left = lists[0]
            right = lists[-1]
            
            head = ListNode(0)
            cur = head
            
            while left and right:
                cur.next = ListNode(0)
                cur = cur.next
                
                if left.val < right.val:
                    cur.val = left.val
                    left = left.next
                else:
                    cur.val = right.val
                    right = right.next
            
            if left:
                cur.next = left
            if right:
                cur.next = right
            
            return head.next
