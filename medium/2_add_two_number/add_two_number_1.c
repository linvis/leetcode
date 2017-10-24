/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode *p = l1, *q = l2, *h = head;
    int carry = 0;
    while (p != NULL || q != NULL) {
        int p_val = (p == NULL) ? 0 : p->val;
        int q_val = (q == NULL) ? 0 : q->val;

        struct ListNode *s = malloc(sizeof(struct ListNode));
        s->next = NULL;
        h->next = s;
        s->val = (p_val + q_val + carry) % 10;
        carry = (p_val + q_val + carry) / 10;


        p = (p == NULL) ? NULL : p->next;
        q = (q == NULL) ? NULL : q->next;
        h = h->next;
    }

    if (carry != 0) {
        struct ListNode *s = malloc(sizeof(struct ListNode));
        s->next = NULL;
        h->next = s;
        s->val = carry % 10;
    }

    return head->next;
}
