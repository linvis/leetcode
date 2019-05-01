/*
 *
 * Two index, one index to iterate to the end node, 
 * the other index, is still N node away from the first index,
 * so when go to the end, the second index is point to the node which need to be delete
 * 
 * Complexity: O(N)
 *
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int cur = 0, end = 0;
    int cur_val = 0;
    struct ListNode* p_cur = head; 
    struct ListNode* p_res = head;
    struct ListNode* p_head = head;
    
    while(p_head->next != NULL) {
        cur = end++ - n;
        if (cur >= 0)
            p_cur = p_cur->next;
        
        p_head = p_head->next;
    }

    if (p_cur == head) {
        if (n == (end + 1)) {
            p_res = p_res->next;
        } else {
            p_cur->next = p_cur->next == NULL ? NULL : p_cur->next->next;
        }
    } else {

        p_cur->next = p_cur->next == NULL ? NULL : p_cur->next->next;
    }
    
    return p_res;
}
