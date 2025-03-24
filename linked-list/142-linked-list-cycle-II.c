/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *p = head, *q = head;
    while(q && q->next)
    {
        p=p->next;
        q=q->next->next;
        if(p==q) break;
    }
    if(!(q && q->next)) return NULL;
    while(head!=p)
    {
        head=head->next;
        p=p->next;
    }
    return head;
}