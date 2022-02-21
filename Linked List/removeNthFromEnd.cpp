/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
*/

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int c = 0;
    ListNode* t = head;
    while(t) {
        ++c;
        t = t->next;
    }
    
    if (n == c) {
        ListNode* x = head->next;
        delete head;
        return x;
    }
    
    n = c-n;
    t  = head;
    c = 0;
    
    while(t) {
        ++c;
        if (n == c) {
            ListNode* x = t->next;
            t->next = t->next->next;
            delete x;
            break;
        }
        t = t->next;
    }
    return head;
}
