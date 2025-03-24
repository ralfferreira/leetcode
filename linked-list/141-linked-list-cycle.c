/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *q, *p;
    p=q=head;

    do
    {
        if (p==NULL || p->next==NULL || q==NULL || q->next==NULL) {
            return false;
        }
        p=p->next;
        q=q->next;
        if(q)
            q = q->next;
        else
            q;
    } while(p && q && p!=q);
    if(p==q)
        return true;
    else
        return false;
}