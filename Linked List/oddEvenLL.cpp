/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.
*/

ListNode* oddEvenList(ListNode* head) {
    if (head) {
        ListNode* o = head, *e = head->next, *eHead = e;
        
        while (e && e->next) {
            o->next = o->next->next;
            e->next = e->next->next;
            
            o = o->next;
            e = e->next;
        }
        o->next = eHead;
    }
    return head;
}
