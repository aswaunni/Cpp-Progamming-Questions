/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
*/

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head)
        return NULL;
    
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode* pre = dummy;
    
    for (int i = 0; i < left-1; i++)
        pre = pre->next;
    
    ListNode* tail = pre->next;
    
    for (int i = 0; i < right-left; i++) {
        ListNode* t = pre->next;
        pre->next = tail->next;
        tail->next = tail->next->next;
        pre->next->next = t;
    }
            
    return dummy->next;
}

// OR

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head)
        return NULL;
    
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode* pre = dummy;
    
    for (int i = 0; i < left-1; i++)
        pre = pre->next;
    
    ListNode* prev = NULL, *cur = pre->next;
    
    for (int i = 0; i <= right-left; i++) {
        ListNode* t = cur->next;
        cur->next = prev;
        prev = cur;
        cur = t;
    }
    
    pre->next->next = cur;
    pre->next = prev;
    
    return dummy->next;
    
}
