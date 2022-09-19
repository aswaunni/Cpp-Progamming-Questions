/*
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 
 */

ListNode* rotateRight(ListNode* head, int k) {
    if (!head)
        return NULL;
    
    int n = 1;
    ListNode* t = head;
    while (t->next) {
        n++;
        t = t->next;
    }
    
    k = k%n;
    if (k == 0)
        return head;
    
    t->next = head;
    ListNode* nHead = NULL;
    
    for (int i = 0; i < n-k; i++)
        t = t->next;
    
    nHead = t->next;
    t->next = NULL;
    
    return nHead;
}
